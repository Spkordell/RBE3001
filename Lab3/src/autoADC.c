/*
 * autoADC.c
 *
 *  Created on: Jan 22, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      Contains functions for initializing the ADC in free run mode as well as an ISR that stores the most recently converted value in the global struct as well as setting a flag indicating that ADC data is available.
 *
 */

#include "main.h"

ADCVariables ADCVars;
/*
 * Initialize an ADC channel to operate in free-run mode, a new conversion will start automatically once the previous conversion is complete.
 */
void initFreeRunADC(unsigned char channel) {
	//disable global interrupts
	cli();

	//set a variable so the ISR know we want to sample only one channel
	ADCVars.ADCSampleAllChannels = 0;
	ADCVars.ADCMultiChannelMask = 0;

	//initialize the ADC
	InitADC(channel);

	//Enable auto trigger
	ADCSRAbits._ADATE = 1;

	//Set ADC to free run mode
	ADCSRBbits._ADTS0 = 0;
	ADCSRBbits._ADTS1 = 0;
	ADCSRBbits._ADTS2 = 0;

	//Enable ADC interrupts
	ADCSRAbits._ADIE = 1;

	//Set channel for autoADC
	ADMUX &= 0b11100000;
	ADMUX |= channel;

	//Start first conversion, ADC will automatically start subsequent conversions after each is completed
	ADCSRAbits._ADSC = 1;

	//enable global interrupts
	sei();
}

//todo: This has been generalized into the multi-channel function below. It can probably be removed.
void initFreeRunADCAllChannels() {
	//disable global interrupts
	cli();

	//set a variable so the ISR know we want to sample all the channels
	ADCVars.ADCSampleAllChannels = 1;
	ADCVars.ADCMultiChannelMask = 0;

	//initialize the ADC
	for(char channel=0; channel < 8; channel++) {
		InitADC(channel);
	}

	//Enable auto trigger
	ADCSRAbits._ADATE = 1;

	//Set ADC to free run mode
	ADCSRBbits._ADTS0 = 0;
	ADCSRBbits._ADTS1 = 0;
	ADCSRBbits._ADTS2 = 0;

	//Enable ADC interrupts
	ADCSRAbits._ADIE = 1;

	//Set first for autoADC
	ADMUX &= 0b11100000;

	//Start first conversion, ADC will automatically start subsequent conversions after each is completed
	ADCSRAbits._ADSC = 1;

	//enable global interrupts
	sei();
}

/*
 *
 * The channels to be sampled are specified by a bit mask. E.x. 0b01100001 would automatically sample ADC channels 0, 5, and 6. The results are still stored in the ADCValues register corresponding to the sampled channel.
 *
 */
void initFreeRunMultiADCChannels(uint8_t channelMask){
	 //ensure a proper channelMask was passed in with at least 1 selected channel
	if (channelMask) {
		//disable global interrupts
		cli();

		//set a variable so the ISR knows we want to sample only certain channels as specified by the channel mask
		ADCVars.ADCSampleAllChannels = 1;
		ADCVars.ADCMultiChannelMask = channelMask;

		//initialize the ADC
		for(char channel=0; channel < 8; channel++) {
			if((channelMask >> channel) & 1) {
				InitADC(channel);
			}
		}

		//Enable auto trigger
		ADCSRAbits._ADATE = 1;

		//Set ADC to free run mode
		ADCSRBbits._ADTS0 = 0;
		ADCSRBbits._ADTS1 = 0;
		ADCSRBbits._ADTS2 = 0;

		//Enable ADC interrupts
		ADCSRAbits._ADIE = 1;

		//Set first channel for autoADC
		ADMUX &= 0b11100000;
		char channel = 0;
		while (!((channelMask >> channel) & 1)) {
			channel++;
		}
		ADMUX |= channel;
		ADCVars.MultiChannelStart = channel;

		//Find last channel for use in ISR
		channel = 7;
		while (!((channelMask >> channel) & 1)) {
			channel--;
		}
		ADCVars.MultiChannelEnd = channel;

		//Start first conversion, ADC will automatically start subsequent conversions after each is completed
		ADCSRAbits._ADSC = 1;

		//enable global interrupts
		sei();
	}
}

/*
 * This ISR is called when conversion is complete and saves the resulting value to a variable in the global struct
 */
ISR(ADC_vect){
	if(ADCVars.ADCSampleAllChannels) {
		char currentChannel = ADMUX & 0b00000111;
		//Note, according to data-sheet, changing ADC channels will take effect on the reading after the next, so save the value in the previous buffer
		if (currentChannel > 0) {
			ADCVars.ADCValues[currentChannel-1] = ADC;
		} else {
			ADCVars.ADCValues[7] = ADC;
		}
		if (currentChannel >= 7) {
			ADMUX &= 0b11100000;
		} else {
			ADMUX++;
		}
	} else if (ADCVars.ADCMultiChannelMask) {
		char currentChannel = ADMUX & 0b00000111;

		//save the ADC value
		if (currentChannel > ADCVars.MultiChannelStart) {
			ADCVars.ADCValues[currentChannel-1] = ADC;
		} else {
			ADCVars.ADCValues[ADCVars.MultiChannelEnd] = ADC;
		}

		//change to the next channel
		ADMUX &= 0b11100000;
		if (currentChannel >= ADCVars.MultiChannelEnd) {
			ADMUX |= ADCVars.MultiChannelStart;
		} else {
			//find next channel
			char channel = currentChannel+1;
			while (!((ADCVars.ADCMultiChannelMask >> channel) & 1)) {
				channel++;
			}
			ADMUX |= channel;
		}
	} else {
		ADCVars.ADCValue = ADC;
		ADCVars.sampleDataAvailable = 1;
	}
}

