/*
 * autoADC.h
 *
 *  Created on: Jan 22, 2014
 *      Author: Steven Kordell, Cody Wall-Epstein, Jiaqi ren
 */


#ifndef AUTOADC_H_
#define AUTOADC_H_

#include "main.h"

typedef struct {
	volatile uint8_t ADCSampleAllChannels;
	volatile uint8_t ADCMultiChannelMask;
	volatile uint8_t MultiChannelStart;
	volatile uint8_t MultiChannelEnd;
	volatile uint8_t sampleDataAvailable;
	volatile uint16_t ADCValues[8];
	volatile uint16_t ADCValue;
} ADCVariables;

extern ADCVariables ADCVars;

void initFreeRunADC(unsigned char channel);
void initFreeRunADCAllChannels();
void initFreeRunMultiADCChannels(uint8_t channelMask);

#endif /* AUTOADC_H_ */
