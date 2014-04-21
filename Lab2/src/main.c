/*
 * main.c
 *
 *  Created on: Jan 19, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 *
 */

#include "main.h"

Globals globals;

int main() {
	initGlobals();	//Initialize globals
	DebugUSARTInit(DEFAULT_BAUD); //initialize USART
	println("Chip Reset");

#if LAB_PART == 'B'

#if MODE == KINEMATICS_DATA_MODE
	float x;
	float y;
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	while(1) {
		calcFPK(&x,&y,getLinkAngle('L'), getLinkAngle('H'));
		printKinData(x, y);
	}
#endif

#if MODE == XY_POSITION_MODE
	initDAC(); 	//initialize the DAC
	initPID(0.01); //Initialize the PID variables //0.01
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	configureButtonInterrupts(); //Initialize Button Interrupts (for selecting desired position)
	//Set initial arm position
	setLinkAngle('L',0);
	setLinkAngle('H',0);
	setConst('H', 30.000, 5.000, 1.000); //19.000, 0.750, 1.005);  //Set high link PID Constants
	setConst('L',45.000, 1.000, 0.200);	//set low link PID Constants
	startPID(); //Starts the timer and begins the PID operations
	float x,y;
	while(1) { //todo, add gravity compensation functions to kinematics.c
		driveLink('H',globals.highLinkPIDOut+((int)cos(getLinkAngle('H')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
		driveLink('L',globals.lowLinkPIDOut+((int)cos(getLinkAngle('L')*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
		calcFPK(&x,&y,getLinkAngle('L'), getLinkAngle('H'));
		printKinData(x, y);
	}
#endif


#if MODE == DRAW_TRIANGLE_POINT_POINT_MODE
	#define TRIANGLE_SPEED 500
	#define TRIANGLE_RESOLUTION 0.01
	float x,y;
	while (1){
		initDAC(); 	//initialize the DAC
		initPID(0.01); //Initialize the PID variables
		initFreeRunADCAllChannels(); //Initialize Auto ADC
		setConst('H', 30.000, 5.000, 1.000); //Set high link PID Constants
		setConst('L',45.000, 1.000, 0.200);	//set low link PID Constants
		//set initial position
		setLinkAngle('L',0);	//45
		setLinkAngle('H',0);	//0
		startPID(); //Starts the timer and begins the PID operations
/*
		while(PINCbits._P7); //Wait for a button to be pressed
		while(!PINCbits._P7); //Wait for a button to be pressed
		smoothArc(0,0,90,90,2000,0.01);
		while(PINCbits._P7); //Wait for a button to be pressed
		while(!PINCbits._P7); //Wait for a button to be pressed
		smoothArc(90,90,0,0,2000,0.01);
		*/

		//while(PINCbits._P7); //Wait for a button to be pressed
		/*
		smoothArc(0,90,0,0,2000,0.01);
		while(1){
			p_fl(getLinkSetPointAngle('L'));
			print("\t");
			p_fl(getLinkSetPointAngle('H'));
			print("\t");
			p_ul(globals.highLinkPIDOut);
			print("\t");
			p_fl(getLinkAngle('L'));
			print("\t");
			p_fl(getLinkAngle('H'));
			println("");
		}
		*/

		while(PINCbits._P7); //Wait for a button to be pressed
		//draw a triangle
		//char* triangle = "A0,90 A0,90 A0,90 A0,90";
		//fillShapeBuffer(triangle);
		smoothArc(0,0,75,-110,TRIANGLE_SPEED,TRIANGLE_RESOLUTION);	//45,0,0,60
		while(shapeVars.t <= 1) {//wait for the arm to finish drawing
			calcFPK(&x,&y,getLinkAngle('L'), getLinkAngle('H'));
			printKinData(x, y);
		}
		//while(PINCbits._P7); //Wait for a button to be pressed
		smoothArc(75,-110,45,-90,TRIANGLE_SPEED,TRIANGLE_RESOLUTION);	//0,60,70,80
		while(shapeVars.t <= 1) {//wait for the arm to finish drawing
			calcFPK(&x,&y,getLinkAngle('L'), getLinkAngle('H'));
			printKinData(x, y);
		}
		//while(PINCbits._P7); //Wait for a button to be pressed
		smoothArc(45,-90,0,0,TRIANGLE_SPEED,TRIANGLE_RESOLUTION);	//70,80,45,0
		while(shapeVars.t <= 1) {//wait for the arm to finish drawing
			calcFPK(&x,&y,getLinkAngle('L'), getLinkAngle('H'));
			printKinData(x, y);
		}

	}
#endif

#if MODE == DRAW_TRIANGLE_RECORD_MODE
	float x,y;
	DDRCbits._P7 = INPUT;
	initDAC(); 	//initialize the DAC
	initPID(0.01); //Initialize the PID variables
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	setConst('H', 30.000, 5.000, 1.000); //19.000, 0.750, 1.005);  //Set high link PID Constants
	setConst('L',45.000, 1.000, 0.200);	//set low link PID Constants
	//set initial position
	setLinkAngle('L',getLinkAngle('L'));
	setLinkAngle('H',getLinkAngle('H'));

	while(PINCbits._P7); //wait for button press to start recoding data
	while(!PINCbits._P7); //wait for button press to replay motion
	println("Recording Data");

	//start a timer that records the points
	globals.pointRecordMaxCount = 5; //lower values means better resolution, but the buffer fills faster
	globals.pointRecordCurrentCount = 0;
	InitTimer(0,NORMAL,255);

	//Slow down the timer by setting a prescaler of 128
	TCCR0Bbits._CS02 = 1;
	TCCR0Bbits._CS01 = 0;
	TCCR0Bbits._CS00 = 1;

	while(PINCbits._P7); //wait for button press to replay motion
	while(!PINCbits._P7); //wait for button press to replay motion

	//stop the timer
	TCCR0Bbits._CS02 = 0;
	TCCR0Bbits._CS01 = 0;
	TCCR0Bbits._CS00 = 0;

	globals.topIndex = globals.lastIndex;

	//prints the saved data
	println("");
	for (long i = 0; i < globals.topIndex; i++) {
		p_fl(globals.lowLinkAngles[i]);
		print(",");
		p_fl(globals.highLinkAngles[i]);
		print(",");
		calcFPK(&x,&y,globals.lowLinkAngles[i], globals.highLinkAngles[i]);
		p_fl(x);
		print(",");
		p_fl(y);
		println("");
		//printKinData(x, y);
	}

	while(1) {
		while(PINCbits._P7); //wait for button press to replay motion
		while(!PINCbits._P7); //wait for button press to replay motion

		println("Replaying Data");
		globals.replayingData = 1;
		globals.lastIndex = 0;

		//restart the timer to replay the motion
		TCCR0Bbits._CS02 = 1;
		TCCR0Bbits._CS01 = 0;
		TCCR0Bbits._CS00 = 1;

		startPID();
	}


#endif


#endif

#if LAB_PART == 'A'

#if MODE == ARM_DATA_MODE
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	//wait for start command from computer
	println("Press \"s\" to start collecting data."); println("");
	while (USART_Receive() != 's');
	while(1) {
		printArmData();
	}
#endif

#if MODE == DAC_DEMO_MODE
	initDAC();
	int DAC0Value = 0;
	int DAC1Value = 4095;
	signed char DAC0State = 1;
	signed char DAC1State = -1;
	while(1) {
		setDAC(0,DAC0Value);
		setDAC(1,DAC1Value);
		if(DAC0Value >= 4095) {
			DAC0State = -1;
		}
		if(DAC1Value >= 4095) {
			DAC1State = -1;
		}
		if(DAC0Value <= 0) {
			DAC0State = 1;
		}
		if(DAC1Value <= 0) {
			DAC1State = 1;
		}
		DAC0Value+=DAC0State;
		DAC1Value+=DAC1State;
	}
#endif

#if MODE == DRIVE_ARM_MODE
	initDAC();
	while(1) {
		driveLink('H',1000);
		driveLink('L',-1000);
		for (long i=0; i<2000000;i++) {
		}
		driveLink('H',-1000);
		driveLink('L',1000);
		for (long i=0; i<2000000;i++) {
		}
	}
#endif

#if MODE == CURRENT_SENSE_MODE
	initDAC(); 	//initialize the DAC
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	configureButtonInterrupts(); //Initialize Button Interrupts (for selecting setpoint since we don't have another pot)
	while(1) {
		//globals.armHighLinkPot = globals.ADCValues[ARM_HIGH_LINK_POT]; //Need to update arm state
		//Print current sensor data
		p_ul(globals.ADCValues[CURRENT_SENSE_0_ADC]);
		print(",");
		p_fl(calculateCurrent(globals.ADCValues[CURRENT_SENSE_0_ADC]));
		print("\t");
		p_ul(globals.ADCValues[CURRENT_SENSE_1_ADC]);
		print(",");
		p_fl(calculateCurrent(globals.ADCValues[CURRENT_SENSE_1_ADC]));
		println("");
	}

#endif

#if MODE == PID_MODE_HIGH || MODE == PID_MODE_LOW
	#if MODE == PID_MODE_HIGH
		char modeC = 'H';
	#else
		char modeC = 'L';
	#endif
	// These seem to work pretty well (without gravity compensation):
	//P = 22.100, I = 3.550 D = 1.860 //Good response, a little overshoot
	//P = 21.630  I = 0.700 D = 0.000 //Good response, very little overshoot
	//P = 26.110, I = 0.550 D = 5.115 //Good response, some undershoot

	// These seem to work pretty well (with gravity compensation):
	// Power Supply: 12V; Current: 3A

	//PID VALUES FOR PART A ON HIGH LINK
	//P = 20.000, I = 0.000, D = 1.500  //Good Response, almost exact
	//P = 18.500, I = 0.000, D = 0.000  //Good Response, almost exact
	//P = 15.200, I = 1.550, D = 0.000  //Very good response, closest yet
	//P = 19.000, I = 0.750, D = 1.005  // Very good @ 45  //used to be 30=P, 5=I, and 1=D moving to diff station

	//PID VALUES FOR PART B ON LOW LINK
	//P = 45.000, I = 1.000, D = 0.200  //Works really well; very close to actual

	//wait for start command from computer
	println("Press \"s\" to start collecting data."); println("");
	while (USART_Receive() != 's');

	initDAC(); 	//initialize the DAC
	initPID(0.01); //Initialize the PID variables //1
	initFreeRunADCAllChannels(); //Initialize Auto ADC
	setLinkAngle(modeC,0);
	startPID(); //Starts the timer and begins the PID operations
	configureButtonInterrupts(); //Initialize Button Interrupts (for selecting setpoint)
	while(1) {
		printPIDValues();
		//setConst(modeC, (float)25.2, (float)1.55, (float)0.00);
		setConst(modeC, (float)globals.ADCValues[KP_POT]*PID_POT_KP_MULTIPLE, (float)globals.ADCValues[KI_POT]*PID_POT_KI_MULTIPLE, (float)globals.ADCValues[KD_POT]*PID_POT_KD_MULTIPLE); //Update the PID constants
		#if ENABLE_GRAVITY_COMPENSATION
			#if MODE == PID_MODE_HIGH
				driveLink(modeC,globals.highLinkPIDOut+((int)cos(getLinkAngle(modeC)*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
			#else
				driveLink(modeC,globals.lowLinkPIDOut+((int)cos(getLinkAngle(modeC)*RADIANS_PER_DEGREE)*500)); //500 is m*l*g
			#endif
		#else
			#if MODE == PID_MODE_HIGH
			driveLink(modeC,globals.highLinkPIDOut);
			#else
			driveLink(modeC,globals.lowLinkPIDOut);
			#endif


		#endif
	}

#endif
#endif
	return 0;
}

ISR(PCINT2_vect) {
#if MODE == XY_POSITION_MODE
	if(!PINCbits._P7) {
		//setArmPosition(230,0);
		setLinkAngle('L',0);
		setLinkAngle('H',0);
	}
	if(!PINCbits._P6) {
		//setArmPosition(125,105);
		setLinkAngle('L',0);
		setLinkAngle('H',90);
	}
	if(!PINCbits._P5) {
		//setArmPosition(0,230);
		setLinkAngle('L',90);
		setLinkAngle('H',0);
	}
	if(!PINCbits._P4) {
		//setArmPosition(-105,125);
		setLinkAngle('L',90);
		setLinkAngle('H',90);
	}
#endif
#if MODE == PID_MODE_HIGH || MODE == PID_MODE_LOW
	#if MODE == PID_MODE_HIGH
		char modeC = 'H';
	#else
		char modeC = 'L';
	#endif
		if(!PINCbits._P7) {
			setLinkAngle(modeC,0);
			println("");
		}
		if(!PINCbits._P6) {
			setLinkAngle(modeC,30);
		}
		if(!PINCbits._P5) {
			setLinkAngle(modeC,45);
		}
		if(!PINCbits._P4) {
			setLinkAngle(modeC,90);
		}
#endif
#if MODE == CURRENT_SENSE_MODE
	if(!PINCbits._P6) {
		driveLink('H',4095);
		driveLink('L',4095);
	}
	if(!PINCbits._P5) {
		driveLink('H',-4095);
		driveLink('L',-4095);
	}
	if(!PINCbits._P4) {
		driveLink('H',0);
		driveLink('L',-0);
	}
#endif
}

#if MODE == DRAW_TRIANGLE_RECORD_MODE

ISR(TIMER0_OVF_vect) {
	if(globals.pointRecordCurrentCount >= globals.pointRecordMaxCount) {
		globals.pointRecordCurrentCount = 0;
		if(globals.replayingData) { //replay the data
			setLinkAngle('L',globals.lowLinkAngles[globals.lastIndex]);
			setLinkAngle('H',globals.highLinkAngles[globals.lastIndex]);
			globals.lastIndex++;
			print("0");
			if (globals.lastIndex >= globals.topIndex) {
				//can't play furthur, turn off the timer
				TCCR0Bbits._CS02 = 0;
				TCCR0Bbits._CS01 = 0;
				TCCR0Bbits._CS00 = 0;
				println("Data Buffer Empty");
			}
		} else { //collect the data
			globals.highLinkAngles[globals.lastIndex] = getLinkAngle('H');
			globals.lowLinkAngles[globals.lastIndex] = getLinkAngle('L');
			globals.lastIndex++;
			print("0");
			if (globals.lastIndex >= MAX_INDEX) {
				//can't log anymore, turn off the timer
				TCCR0Bbits._CS02 = 0;
				TCCR0Bbits._CS01 = 0;
				TCCR0Bbits._CS00 = 0;
				globals.topIndex = MAX_INDEX;
				println("Data Buffer Full");
			}
		}

	} else {
		globals.pointRecordCurrentCount++;
	}
}

#endif


/*
 * Prints the Orientation of potentiometer in ADC counts, pot output in millivolts, and arm orientation in degrees.
 */
void printArmData() {
	int LOW_ADC_Val = globals.ADCValues[ARM_LOW_LINK_POT];
	int HIGH_ADC_Val = globals.ADCValues[ARM_HIGH_LINK_POT];
	p_ul(LOW_ADC_Val);
	print(",");
	p_ul(HIGH_ADC_Val);
	print(",");
	p_ul(LOW_ADC_Val*((float)5/1023)*1000);
	print(",");
	p_ul(HIGH_ADC_Val*((float)5/1023)*1000);
	print(",");
	p_fl(getLinkAngle('L'));
	print(",");
	p_fl(getLinkAngle('H'));
	println("");
}

void printADCValues() {
	p_ul(globals.ADCValues[ARM_HIGH_LINK_POT]);
	print("\t");
	p_ul(globals.ADCValues[ARM_LOW_LINK_POT]);
	print("\t");
	p_ul(globals.ADCValues[KP_POT]);
	print("\t");
	p_ul(globals.ADCValues[KI_POT]);
	print("\t");
	p_ul(globals.ADCValues[KD_POT]);
	println("");
}

void printPIDValues(){

#if MODE == PID_MODE_HIGH
	p_fl(getLinkSetPointAngle('H'));
	print(",");
	p_fl(getLinkAngle('H'));
	print(",");
	p_fl((float)(globals.highLinkPIDOut+(cos(getLinkAngle('H')*RADIANS_PER_DEGREE)*500))*(DAC_MAX_VOLTAGE/DAC_MAX_VALUE)*1000);
	print(",");
	p_fl(calculateCurrent(globals.ADCValues[CURRENT_SENSE_1_ADC])*1000);


	print("\t");
	p_fl(pidConst.Kp_H);
	print("\t");
	p_fl(pidConst.Ki_H);
	print("\t");
	p_fl(pidConst.Kd_H);

#else
	p_fl(getLinkSetPointAngle('L'));
	print(",");
	p_fl(getLinkAngle('L'));
	print(",");
	p_fl((float)(globals.lowLinkPIDOut+(cos(getLinkAngle('L')*RADIANS_PER_DEGREE)*500))*(DAC_MAX_VOLTAGE/DAC_MAX_VALUE)*1000);
	print(",");
	p_fl(calculateCurrent(globals.ADCValues[CURRENT_SENSE_0_ADC])*1000);

	print("\t");
	p_fl(pidConst.Kp_L);
	print("\t");
	p_fl(pidConst.Ki_L);
	print("\t");
	p_fl(pidConst.Kd_L);
#endif


	println("");
}

void printKinData(float x, float y){
	p_fl(x);
	print(",");
	p_fl(y);
	print(",");
	p_fl(getLinkAngle('L'));
	print(",");
	p_fl(getLinkAngle('H'));
	println("");
}
