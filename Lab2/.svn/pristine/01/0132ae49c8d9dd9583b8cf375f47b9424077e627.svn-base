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

/*
 * Initialize an ADC channel to operate in free-run mode, a new conversion will start automatically once the previous conversion is complete.
 */
void initFreeRunADC(unsigned char channel) {
	//disable global interrupts
	cli();

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



/*
 * This ISR is called when conversion is complete and saves the resulting value to a variable in the global struct
 */
ISR(ADC_vect){
	globals.ADCValue = ADC;
/*	if (globals.sampleDataAvailable == 1) {
		print("MISSED SAMPLE");
	}*/
	globals.sampleDataAvailable = 1;
}

