/*
 * ADC.c
 *
 *  Created on: Jan 22, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *
 *      This file contains functions for initializing the ADC pn a channel, pooling that channel for the converted value, and turning off conversion on an ADC channel
 */

#include "main.h"


/*
 * Initializes the ADC on a specific channel. Also disables digital input on that channel to save power.
 */
void InitADC(unsigned char channel) {
	//Set Port A register for the corresponding channel to input
	DDRA &= ~(1 << channel);

	//Disable digital input on ADC channel to save power
	DIDR0 |= (1 << channel);

	//Set ADC voltage reference to AVCC with external capacitor at AREF pin (5V)
	ADMUXbits._REFS1 = 0;
	ADMUXbits._REFS0 = 1;

	//Select the ADC prescaler to division factor of 128
	//lowest possible value results in highest precision but lengthy sample time
	ADCSRAbits._ADPS2 = 1;
	ADCSRAbits._ADPS1 = 1;
	ADCSRAbits._ADPS0 = 1;

	//Enable the ADC
	ADCSRAbits._ADEN = 1;
}

/*
 * Enables the digital input for an ADC channel
 */
void ClearADC(unsigned char channel) {
	//Set PORT A register for corresponding channel to input
	DDRA |= (1 << channel);

	//Enable digital input on this channel
	DIDR0 &= ~(1 << channel);

	//Clear ADC data registers
	ADCH = 0;
	ADCL = 0;
	ADC = 0;
}

/*
 * Starts a conversion on an ADC channel, waits for the conversion to complete, then return the converted value.
 */
unsigned short GetADC(unsigned char channel) {
	//Select the channel
	ADMUX &= 0b11100000;
	ADMUX |= channel;

	//Start an ADC conversion
	ADCSRAbits._ADSC = 1;

	//wait for conversion to complete
	while(ADCSRA & (1<<ADSC));
	return ADC;
}



