/*
 * DAC.c
 *
 *  Created on: Jan 29, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

void initDAC() {
	//Initialize SPI (note: The DAC can operate with a clock as high as 50MHz)
	GenericSPIInit();
	//Set DAC SS pin to output
	DDRDbits._P4 = OUTPUT;
	//Power up DAC (using internal voltage reference)
	PORTDbits._P4 = 0;
	SPITransceive(0b01101111);
	SPITransceive(0);
	SPITransceive(0);
	PORTDbits._P4 = 1;
}

/*
 * Sets the value of a DAC channel (0-4095)
 */
void setDAC(unsigned char DACn, unsigned int SPIVal){
	//write DAC CS signal low
	PORTDbits._P4 = 0;
	//transmit command and address
	//Command: Write to and Update (Power Up) DAC Register n: 0b0011
	SPITransceive(0b00110000|DACn);
	//Transmit data (12 bit DAC)
	SPITransceive(SPIVal >> 4);
	SPITransceive(0x00FF & (SPIVal << 4));
	//write DAC CS signal high (command executed)
	PORTDbits._P4 = 1;
}

/*
 * Sets the voltage of the DAC to a value between 0 and 2.5 v
 */
void setDACVoltage(unsigned char DACn, float voltage) {
	setDAC(DACn,voltage*(DAC_MAX_VALUE/DAC_MAX_VOLTAGE));
}
