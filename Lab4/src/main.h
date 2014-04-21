/*
 * main.h
 *
 *  Created on: Feb 19, 2014
 *      Author: Steven Kordell
 */

#ifndef MAIN_H_
#define MAIN_H_

//Dependencies
#include "DAC.h"
#include "PID.h"
#include <avr/io.h>
#include <math.h>
#include "RBELib/RBELib.h"
#include "globals.h"
#include "autoADC.h"
#include "encoder.h"
#include "kinematics.h"
#include "armActuator.h"
#include "currentSensor.h"
#include "stateMachine.h"
#include "myatof.h"

//Constants
#define MOTOR_VOLTAGE 12

//TODO: organize these constants

//ADC Input Channels
#define CURRENT_SENSE_0_ADC 0
#define CURRENT_SENSE_1_ADC 1
#define ARM_LOW_LINK_POT 2
#define ARM_HIGH_LINK_POT 3
#define BLOCK_SENSE_IR 4
#define TRIGGER_IR 5

//Servo Channels
#define CONVEYER_SERVO 0
#define GRIPPER_SERVO 1

//special arm configurations and measurements
#define HIGH_LINK_DEFAULT_ANGLE -82.5 //degrees
#define LOW_LINK_DEFAULT_ANGLE 38.5 //degrees
#define DEFAULT_X_POSITION 170 //mm
#define DEFUALT_Y_POSITION 15 //mm
#define ARM_LIFT_X_POSITION 216 //mm
#define ARM_LIFT_Y_POSITION 45 //mm
#define HEIGHT_ABOVE_BLOCK 5.2 //cm
#define DROPOFF_BLOCK_HEIGHT 4.5 //cm
#define HEAVY_WEIGHT_IR_POSITION 340
#define LIGHT_WEIGHT_IR_POSITION 450
#define IR_POSITION_OFFSET 5.5 //cm, distance IR is from the arm

//Time offsets (seconds)
#define BLOCK_NOISE_CHECK_TIME 0.2
#define BLOCK_TRAVEL_TIME 0.05
#define ARM_DROP_TIME 0.3
#define GRIPPER_CLOSE_TIME 0.4
#define ARM_LIFT_TIME 0.5
#define GRIPPER_OPEN_TIME 0.2
#define CURRENT_SUM_TIME 0.1
#define ARM_SET_TIME 0.5

//Various thresholds
#define MIN_BLOCK_DETECTION_THRESHOLD 310
#define MIN_BLOCK_TRIGGER_THRESHOLD 260
#define HEAVY_THRESHOLD 300
#define LIGHT_THRESHOLD 300
#define THRESHOLD_OFFSET 0
#define DEFAULT_IR_VALUE 400

//Program Modes
#define IR_DATA_COLLECT_MODE 0
#define SERVO_TEST_MODE 1
#define PRINT_FK_MODE 2
#define CURRENT_SENSE_MODE 3
#define FINAL_PROJECT_MODE 4
#define ROBOT_CONTROL_MODE 5

#define MODE 4

//create enum for block weights
typedef enum {
	HEAVY,
	LIGHT
} BLOCK_WEIGHT;

///////////////////function prototypes///////////////////

////State Specific functions
void initialize();

////Additional Helper functions
void startConveyer();
void openGripper();
void closeGripper();
float IRDistance(uint16_t IRValue);

#endif /* MAIN_H_ */
