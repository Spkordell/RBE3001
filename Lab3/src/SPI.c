/*
 * SPI.c
 *
 *  Created on: Jan 29, 2014
 *      Author: Steven Kordell
 */

#include "main.h"


void GenericSPIInit(void) {
	// Set MOSI and SCK output
	DDRBbits._P7 = OUTPUT; //SCK
	DDRBbits._P5 = OUTPUT; //MOSI
	//Set MISO to input
	DDRBbits._P6 = INPUT;
	//Set AVR SS high (Ensure AVR is in Master Mode)
	DDRBbits._P4 = OUTPUT;
	PORTBbits._P4 = 1;

	SPCRbits._SPE = 1; 	//Enable SPI
	SPCRbits._MSTR = 1; //Set master mode

	//set clock rate f_cpu/2
	/*SPCRbits._SPR0 = 0;
	SPCRbits._SPR1 = 0;
	SPSRbits._SPI2X = 1;*/

	//set clock rate f_cpu/32
	SPCRbits._SPR0 = 0;
	SPCRbits._SPR1 = 1;
	SPSRbits._SPI2X = 1;
}

BYTE SPITransceive(BYTE data) {
	//Starts transmission
	SPDR = data;
	// Wait for transmission to complete
	while (!(SPSR & (1<<SPIF)));
	//Read any received data
	return SPDR;
}
