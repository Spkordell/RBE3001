/*
 * PWM.c
 *
 *  Created on: Jan 24, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      This file contains the functions necessary for creating a PWM square wave of variable frequency and duty cycle on a digital pin utilizing timer 1 in CTC mode.
 */

#include "main.h"

/*
 * Initializes PWM on a given port and pin at a given frequency and duty cycle. The final parameter sets the compare value for the timer. Lower compare values result in higher accuracy, but result in more CPU interrupts. The best values are divisible by the input F_CPU/frequency.
 */
void initPWM(uint8_t port, uint8_t pin, float frequency, float duty, uint16_t compare) {
	globals.PWMPort = port;
	globals.PWMPin = pin;
	globals.PWMFrequency = frequency;
	globals.PWMDuty = duty;
	globals.PWMCompare = compare;
	// Set output direction on pin
	switch(port) {
	case 'A':
		DDRA |= (1 << pin);
		break;
	case 'B':
		DDRB |= (1 << pin);
		break;
	case 'C':
		DDRC |= (1 << pin);
		break;
	case 'D':
		DDRD |= (1 << pin);
		break;
	}
	globals.PWMMaxTime = ((F_CPU/globals.PWMCompare))*(1/(globals.PWMFrequency));
	globals.PWMHighTime = (globals.PWMMaxTime*globals.PWMDuty);
	globals.PWMCurrentCount = 0;
	InitTimer(1,CTC,globals.PWMCompare);
}

/*
 * Sets the PWM duty cycle
 */
void setPWMDuty(float duty) {
	globals.PWMDuty = duty;
	globals.PWMHighTime = (globals.PWMMaxTime*globals.PWMDuty);
}

/*
 * Sets the PWM frequency
 */
void setPWMFrequency(float frequency) {
	globals.PWMFrequency = frequency;
	globals.PWMMaxTime = ((F_CPU/globals.PWMCompare))*(1/(globals.PWMFrequency));
	globals.PWMHighTime = (globals.PWMMaxTime*globals.PWMDuty);
}

/*
 * Sets the PWM digital pin high
 */
void pinHigh() {
	switch(globals.PWMPort) {
	case 'A':
		PORTA |= (1 << globals.PWMPin);
		break;
	case 'B':
		PORTB |= (1 << globals.PWMPin);
		break;
	case 'C':
		PORTC |= (1 << globals.PWMPin);
		break;
	case 'D':
		PORTD |= (1 << globals.PWMPin);
		break;
	}
}

/*
 * Sets the PWM digital pin low
 */
void pinLow() {
	switch(globals.PWMPort) {
	case 'A':
		PORTA &= ~(1 << globals.PWMPin);
		break;
	case 'B':
		PORTB &= ~(1 << globals.PWMPin);
		break;
	case 'C':
		PORTC &= ~(1 << globals.PWMPin);
		break;
	case 'D':
		PORTD &= ~(1 << globals.PWMPin);
		break;
	}
}

/*
 * This ISR is called by the timer. it sets the output pin high or low depending on the current waveform position to achieve the desired frequency and duty cycle. If the MODE is set to SAMPLEADCMODE, this ISR will also start an ADC conversion.
 */
ISR(TIMER1_COMPA_vect) {
	if(globals.PWMCurrentCount <= globals.PWMHighTime) {
		pinHigh();
	} else {
		pinLow();
		if(globals.PWMCurrentCount >= globals.PWMMaxTime) {
			globals.PWMCurrentCount = 0;
			#if MODE == SAMPLEADCMODE
				//start an ADC Conversion
				ADCSRAbits._ADSC = 1;
				//latch the time
				globals.latchedCycles = globals.elapsedCycles;
			#endif
		}
	}

	#if MODE == SAMPLEADCMODE
		globals.elapsedCycles++;;
	#endif

	globals.PWMCurrentCount++;
}

