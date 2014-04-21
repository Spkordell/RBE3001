/*
 * main.c
 *
 *  Created on: Jan 19, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 *      This file contains the main routine for the first RBE3001 lab: Intro to AVR. It also contains a few task-specific supporting functions.
 *
 */

#include "main.h"

//function prototypes
void printTimeData(unsigned short ADCValue);
void printPWMData();

//Program constants
#define POTCHAN 4 //define channel the potentiometer is connected to
#define POTANGLE 300 //the angle through which the potentiometer can rotate

//Modes (for different lab parts)
#define DATACOLLECTMODE 2
#define PWMMODE 3
#define SAMPLEADCMODE 5

//The mode to use
#define MODE SAMPLEADCMODE

//Create struct to store global variables (some ISR require global variables)
Globals globals;

/*
 * The main routine for the lab. It's operation will depend on the value of the MODE define above. Use the MODE define to select which portion of the lab to run.
 *
 * DATACOLLECTMODE: Samples the ADC on POTCHAN and prints information to the terminal including a timestamp and the ACC value, voltage, and potentiometer angle
 * PWMMODE: Outputs a square wave on pin B3. The frequency of the square wave is determined by the buttons on the board and the duty cycle is controlled by a potentiometer connected to POTCHANN. Information regarding the PWM frequency and duty cycle will be printed to the terminal.
 * SAMPLEADCMODE: When the button connected to pin D7 is pressed, the AVR will sample the the POTCHAN ADC pin for one second at 225hz. The data will be printed to the terminal along with a timestamp.
 *
 */
int main() {
	initGlobals();	//Initialize globals
	DebugUSARTInit(DEFAULT_BAUD); //initialize USART

#if MODE == PWMMODE
	initFreeRunADC(POTCHAN); //InitializeADC for auto-conversion
	println("Press \"s\" to start collecting data."); println("");
	while (USART_Receive() != 's');
	initPWM('B',3,100,.50,576);
	configureButtonInterrupts(); //Configure the buttons for interrupts
	//calculate in advance the number of seconds that occurs between each timer interrupt
	while(1) {
		setPWMDuty((float)globals.ADCValue/1023);
		printPWMData();
	}
#endif
#if MODE == DATACOLLECTMODE
	initFreeRunADC(POTCHAN); //InitializeADC for auto-conversion
	//wait for start command from computer
	println("Press \"s\" to start collecting data."); println("");
	while (USART_Receive() != 's');
	initTimeStamp();
	while(1) {
		printTimeData(globals.ADCValue);
	}
#endif
#if MODE == SAMPLEADCMODE
	InitADC(POTCHAN);

	//Some additional ADC setup
	//Initialize ADC interrupts
	ADCSRAbits._ADIE = 1;
	//Set ADC channel
	ADMUX &= 0b11100000;
	ADMUX |= POTCHAN;

	//configure a button
	DDRDbits._P7 = INPUT;

	while(1) {
		println("Press button 7 to begin sampling ADC 4");
		//wait for the button to be pressed and released before starting
		while(PINDbits._P7);
		while(!PINDbits._P7);

		//reset all global variables to prepare to sample again
		initGlobals();

		//Start the sampling (ADC conversion is initialized by the timer ISR and captured in the ADC ISR)
		initPWM('B',3,225,.5,320);

		//calculate in advance the number of seconds that occurs between each timer interrupt
		float secondsPerCycle =  (float)globals.PWMCompare/F_CPU;

		//transmit data as it becomes available
		while(globals.latchedCycles*secondsPerCycle < 1) {
			if (globals.sampleDataAvailable) {
				//print time stamp
				println("");
				printfDEBUG_FL(globals.latchedCycles*secondsPerCycle);
				print(",");
				//print the ADC reading
				p_ul(globals.ADCValue);
				globals.sampleDataAvailable = 0;
			}
		}

		println("Sampling Complete");
	}
#endif

	return 0;
}

/*
 * This ISR changes the frequency of the PWM wave when one of the buttons on Pins D4-D7 are pressed.
 */
ISR(PCINT3_vect) {
	if(PINDbits._P7 == 0) {
		setPWMFrequency(100);
	}
	if(PINDbits._P6 == 0) {
		setPWMFrequency(20);
	}
	if(PINDbits._P5 == 0) {
		setPWMFrequency(1);
	}
	if(PINDbits._P4 == 0) {
		setPWMFrequency(.5);
	}
}

/*
 * Prints the duty cycle, frequency, state, pot value, and pot voltage to the serial port.
 */
void printPWMData() {

	printfDEBUG_FL(globals.PWMDuty*100);
	print(",");
	printfDEBUG_FL(globals.PWMFrequency);
	print(",");
	if (PINBbits._P3) {
		print("HIGH");
	} else {
		print ("LOW");
	}
	print(",");
	p_ul(globals.ADCValue);
	print(",");
	p_ul((globals.ADCValue*((float)5/1023))*1000);
	println("");
}

 /*
  * Prints the timestamp, ADC reading, ADC voltage, and potentiometer angle to the terminal.
  */
void printTimeData(unsigned short ADCValue) {
	p_ul(globals.Hour);
	print(":");
	p_ul(globals.Minute);
	print(":");
	p_ul(globals.Second);

	print(",");
	p_ul(globals.ADCValue);
	print(",");
	p_ul((globals.ADCValue*((float)5/1023))*1000);
	print(",");
	p_ul(globals.ADCValue*((float)POTANGLE/1023));
	println("");
}
