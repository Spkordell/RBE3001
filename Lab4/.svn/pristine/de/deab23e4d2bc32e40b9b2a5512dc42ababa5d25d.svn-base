/*
 * stateMachine.h
 *
 *  Created on: Mar 2, 2014
 *      Author: spkordell
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "main.h"

//Create enum to store states of state machine
typedef enum {
   INITIALIZE, //Initialize the arm
   READY_ARM, // Move the arm into the ready position above the center of the conveyer belt
   WAIT_FOR_BLOCK, //Wait for the first IR to detect the block
   WAIT_FOR_BLOCK_NOISE_CHECK, //ensure we didn't get a false detection from noise by checking again after a short delay
   PREP_FOR_PICKUP, //Move the arm above the location where the block is going to be
   WAIT_FOR_RISING_TRIGGER, //wait for the second IR to detect the block
   WAIT_FOR_RISING_TRIGGER_NOISE_CHECK, //check for false detection from noise
   WAIT_FOR_FALLING_TRIGGER, //wait until the second sensor no longer sees the block, block is in pickup position
   MOVE_TO_PICKUP, //Move the arm over the block, ready to grasp it
   GRAB_BLOCK, //close the gripper and grab the block
   PICKUP_BLOCK, //pick the block up off the conveyer belt
   DETERMINE_WEIGHT, //determine the weight of the block with current sensing
   MOVE_TO_SORT, //move the block to the corresponding location based on it's weight class
   DROP_TO_SORT //release the block in it's sorted location, from here, the cycle repeats from READY_ARM
} TASKSTATE;


////State machine control Functions
void engageState(TASKSTATE currentState);
TASKSTATE updateState(TASKSTATE currentState);
void printState(TASKSTATE currentState);

void setStateDelayTimer(float period);
void stopStateDelayTimer();

#endif /* STATEMACHINE_H_ */
