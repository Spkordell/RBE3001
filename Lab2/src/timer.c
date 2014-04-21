/*
 * timer.c
 *
 *  Created on: Jan 22, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *		Contains the functions for initializing a timer in either NORMAL or CTC mode as well as changing the COMPA value for timers initated in CTC mode.
 */

#include "main.h"

/*
 * Initializes any timer (0,1, or 2) in either NORMAL or CTC mode. In NORMAL mode the third comp parameter has no effect, in CTC mode the comp parameter sets the comparison A value.
 * No clock prescaling is used.
 */
void InitTimer(unsigned char number, unsigned char mode, unsigned short int comp) {
	//disable global interrupts while we set up the timer
	cli();

	switch(number) {
	case 0:
		//Initialize timer to 0
		TCNT0 = 0;
		//disable prescaler
		TCCR0Bbits._CS02 = 0;
		TCCR0Bbits._CS01 = 0;
		TCCR0Bbits._CS00 = 1;
		//enable Timer overflow interrupt:
		TIMSK0bits._TOIE0 = 1;
		//Enable Timer interrupt flag
		TIFR0bits._TOV0 = 1;
		break;
	case 1:
		//Initialize timer to 0
		TCNT1 = 0;
		//disable prescaler
		TCCR1Bbits._CS12 = 0;
		TCCR1Bbits._CS11 = 0;
		TCCR1Bbits._CS10 = 1;
		//enable Timer overflow interrupt:
		TIMSK1bits._TOIE1 = 1;
		//Enable Timer interrupt flag
		TIFR1bits._TOV1 = 1;
		break;
	case 2:
		//Initialize timer to 0
		TCNT2 = 0;
		//disable prescaler
		TCCR2Bbits._CS22 = 0;
		TCCR2Bbits._CS21 = 0;
		TCCR2Bbits._CS20 = 1;
		//enable Timer overflow interrupt:
		TIMSK2bits._TOIE2 = 1;
		//Enable Timer interrupt flag
		TIFR2bits._TOV2 = 1;
		break;
	}
	if (mode == CTC) {
		//Enable CTC mode
		switch(number) {
		case 0:
			//Set mode to CTC
			TCCR0Abits._WGM00 = 0;
			TCCR0Abits._WGM01 = 1;
			TCCR0Bbits._WGM02 = 0;
			OCR0A = comp; //Set comparison value
			//Enable timer interrupts for CTC mode
			TIMSK0bits._OCIE0A = 1;
			//Clear timer compare match flag
			TIFR0bits._OCF0A = 1;
			break;
		case 1:
			//Set mode to CTC
			TCCR1Abits._WGM10 = 0;
			TCCR1Abits._WGM11 = 0;
			TCCR1Bbits._WGM12 = 1;
			TCCR1Bbits._WGM13 = 0;
			OCR1A = comp; //Set comparison value
			//Enable timer interrupts for CTC mode
			TIMSK1bits._OCIE1A = 1;
			//Clear timer compare match flag
			TIFR1bits._OCF1A = 1;
			break;
		case 2:
			//Set mode to CTC
			TCCR2Abits._WGM20 = 0;
			TCCR2Abits._WGM21 = 1;
			TCCR2Bbits._WGM22 = 0;
			OCR2A = comp; //Set comparison value
			//Enable timer interrupts for CTC mode
			TIMSK2bits._OCIE2A = 1;
			//Clear timer compare match flag
			TIFR2bits._OCF2A = 1;
			break;
		}
	}
    //enable global interrupts
    sei();
}

/*
 * Sets a timers comparison A value. Only has an effect for timers in CTC mode.
 */
void setCompValue(unsigned char number, unsigned short int comp) {
	switch(number) {
	case 0:
		OCR0A = comp; //Set comparison value
		break;
	case 1:
		OCR1A = comp; //Set comparison value
		break;
	case 2:
		OCR2A = comp; //Set comparison value
		break;
	}
}
