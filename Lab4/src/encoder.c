/*
 * encoder.c
 *
 *  Created on: Feb 12, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

/*
 * Initializes an encoder for a specified link
 */
void initEncoder(char which) {
	//Initialize SPI
	GenericSPIInit();

	//Set SS to output
	DDRC |=  which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS); //set bits
	//set SS high
	PORTC |= which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);

	//Clear the cntr register
	PORTC &= which == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	SPITransceive(CLR_CNTR);
	PORTC |= which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);

	//set operating mode
	PORTC &= which == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	SPITransceive(WRITE_MDR0);
	SPITransceive(QUADRX1|FREE_RUN|DISABLE_INDX|ASYNCH_INDX|FILTER_1);
	PORTC |= which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);
	PORTC &= which == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	SPITransceive(WRITE_MDR1);
	SPITransceive(NO_FLAGS|BYTE_2|EN_CNTR);
	PORTC |= which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);
}

/*
 * Initializes the encoders for both links
 */
void initEncoders() {
	initEncoder('H');
	initEncoder('L');
}

/*
 * sets the encoder counts for a speicifed link to zero
 */
void resetEncoderCount(char which) {
	//Clear the cntr register
	PORTC &= which == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	SPITransceive(CLR_CNTR);
	PORTC |= which == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);
}

/*
 * Sets the encoder counts for both links to zero
 */
void resetEncoderCounts() {
	resetEncoderCount('H');
	resetEncoderCount('L');
}


/*
 * Outputs the number of encoder pulses received since the last sample time. If __chan = 'L', the function returns the number of counts for motor channel 0, if __chan = 'H;, the function returns the number of counts for motor channel 1. The function must return a value of -1 in an invalid channel is requested.
 *
 */
int16_t encoderCounts(int chan) {
	if (chan != 'H' && chan != 'L') {
		return -1; //Invalid channel
	}
	//Read the counter
	PORTC &= chan == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	int16_t counts;
	PORTC &= chan == 'H' ? ~(1 << HIGH_ENCODER_SS) : ~(1 << LOW_ENCODER_SS);
	SPITransceive(READ_CNTR);
	counts = SPITransceive(0xFF) << 8;
	counts |= SPITransceive(0xFF);
	PORTC |= chan == 'H' ? (1 << HIGH_ENCODER_SS) : (1 << LOW_ENCODER_SS);
	return -counts;
}
