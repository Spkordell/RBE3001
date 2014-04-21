/*
 * main.c
 *
 *  Created on: Feb 19, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

Globals globals;

int main() {
	DebugUSARTInit(DEFAULT_BAUD); //Start serial transmissions
	initGlobals(); //initialize any global variables
	println("Chip Reset"); //print a message to the terminal so we are made aware of any unexpected power cycles or other issues which might cause the chip to spontaneously reset. Also lets us know everything is working.

#if MODE == FINAL_PROJECT_MODE
	//final project main code
	TASKSTATE currentState = INITIALIZE;
	while(1) {
		engageState(currentState);
		currentState = updateState(currentState);
		//printState(currentState);
		printArmConfiguration();
	}
#endif

#if MODE == IR_DATA_COLLECT_MODE
	//prints the IR readings to the terminal for data collection
	InitADC(BLOCK_SENSE_IR);
	InitADC(TRIGGER_IR);
	while(1) {
		p_ul(GetADC(BLOCK_SENSE_IR));
		print("\t");
		p_ul(GetADC(TRIGGER_IR));
		print("\t");
		p_fl(IRDistance(GetADC(BLOCK_SENSE_IR)));
		print("\t");
		p_fl(IRDistance(GetADC(TRIGGER_IR)));
		println("");
	}
#endif

#if MODE == ROBOT_CONTROL_MODE
	//ALlows one to control the arm with commands sent over the terminal (or through matlabP
	initDAC(); //Initialize the DAC
	initPID(0.01); //Initialize PID variables
	initFreeRunMultiADCChannels((1 << ARM_HIGH_LINK_POT)|(1 << ARM_LOW_LINK_POT)|(1 << BLOCK_SENSE_IR)|(1 << TRIGGER_IR)|(1 << CURRENT_SENSE_0_ADC)|(1 << CURRENT_SENSE_1_ADC)); //Initialize the ADC
	setConst('H', 30.000, 5.000, 0.100); //Set high link PID Constants
	setConst('L',45.000, 1.000, 0.100);	//set low link PID Constants
	setLinkAngle('L',0); //set initial position
	setLinkAngle('H',0); //set initial position
	startPID(); //PID controller is now running
	char link;
	char dataBuffer[20];
	char* dataPtr;
	while(1) {
		link = USART_Receive();
		putCharDebug(link);
		if (link == 'L' || link == 'H') {
			dataPtr = dataBuffer;
			do {
				*dataPtr = USART_Receive();
				putCharDebug(*dataPtr);
			} while (*dataPtr++ != 'E');
			println("");
			setLinkAngle(link,myatof(dataBuffer));
		}
	}
#endif

#if MODE == SERVO_TEST_MODE
	//testing the various servos
	startConveyer();
	println("Conveyer Started");
	openGripper();
	println("Gripper Opened");
	for(int i = 0; i < 5000;i++) {print("\r\r\r\r\r\r\r\r");}
	closeGripper();
	println("Gripper Closed");
	while(1);
#endif

#if MODE == PRINT_FK_MODE
	//Prints the arm's configuration and cartesion position, for testing and finding various position constants
	initDAC(); //Initialize the DAC
	initFreeRunMultiADCChannels((1 << ARM_HIGH_LINK_POT)|(1 << ARM_LOW_LINK_POT)); //Initialize the ADC
	float x;
	float y;
	while(1) {
		calcFPK(&x, &y, getLinkAngle('L'), getLinkAngle('H'));
		p_fl(getLinkAngle('H'));
		print("   ");
		p_fl(getLinkAngle('L'));
		print("   ");
		p_fl(x);
		print("   ");
		p_fl(y);
		println("");
	}
#endif

#if MODE == CURRENT_SENSE_MODE
	//outputs the current sense data to the terminal, for testing
	initDAC(); //Initialize the DAC
	initPID(0.01); //Initialize PID variables
	initFreeRunMultiADCChannels((1 << ARM_HIGH_LINK_POT)|(1 << ARM_LOW_LINK_POT)|(1 << CURRENT_SENSE_0_ADC)|(1 << CURRENT_SENSE_1_ADC)); //Initialize the ADC
	setConst('H', 30.000, 5.000, 0.100); //Set high link PID Constants
	setConst('L',45.000, 1.000, 0.100);	//set low link PID Constants
	setLinkAngle('H',HIGH_LINK_DEFAULT_ANGLE);
	setLinkAngle('L',LOW_LINK_DEFAULT_ANGLE);
	startPID(); //PID controller is now running
	while(1) {
		//print the combined current draw to the terminal
		p_fl(calculateCurrent(ADCVars.ADCValues[CURRENT_SENSE_0_ADC])+calculateCurrent(ADCVars.ADCValues[CURRENT_SENSE_1_ADC]));
		println("");
	}
#endif

	return 0;
}


//////////////////Helper methods below this point//////////////////////
/*
 * This function initializes the DAC, PID, ADC, and servos. Arm should be ready to function after this.
 */
void initialize() {
	openGripper(); //Open the gripper
	println("INITIALIZE");
	initDAC(); //Initialize the DAC
	initPID(0.01); //Initialize PID variables
	initFreeRunMultiADCChannels((1 << ARM_HIGH_LINK_POT)|(1 << ARM_LOW_LINK_POT)|(1 << BLOCK_SENSE_IR)|(1 << TRIGGER_IR)|(1 << CURRENT_SENSE_0_ADC)|(1 << CURRENT_SENSE_1_ADC)); //Initialize the ADC
	setConst('H', 30.000, 5.000, 0.100); //Set high link PID Constants
	setConst('L',45.000, 1.000, 0.100);	//set low link PID Constants
	setLinkAngle('L',0); //set initial position
	setLinkAngle('H',0); //set initial position
	startPID(); //PID controller is now running
	startConveyer(); //Start the conveyer belt
}

/*
 * Starts the conveyer belt
 */
void startConveyer() {
	SetServo(CONVEYER_SERVO,60);
}

/*
 * Opens the gripper
 */
void openGripper() {
	 SetServo(GRIPPER_SERVO,0);
}

/*
 * closes the gripper
 */
void closeGripper() {
	 SetServo(GRIPPER_SERVO,180);
}

/*
 * Converts raw IR data into the equivilent distance in cm
 */
float IRDistance(uint16_t IRValue){
	if (IRValue < MIN_BLOCK_DETECTION_THRESHOLD) {
		IRValue = DEFAULT_IR_VALUE;
	} //prevents detection beyond a certain threshold
	return .00005*IRValue*IRValue - 0.0739*IRValue + 33.604; //The coefficients in this function were determined empirically
}


