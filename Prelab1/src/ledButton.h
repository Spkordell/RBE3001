/*
 * ledButton.h
 *
 *  Created on: Jan 19, 2014
 *      Author: Steven Kordell
 */

#ifndef LEDBUTTON_H_
#define LEDBUTTON_H_

#include "main.h"

 #define LED PB0 // Define ext led pin on PB0
 #define BUTTON PD0 // Define ext switch pin on PB1

void initializeButtonAndLED();
void lightLEDForButton();

#endif /* LEDBUTTON_H_ */
