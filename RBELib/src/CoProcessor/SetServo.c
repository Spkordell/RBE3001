/*
 * SetServo.c
 *
 *  Created on: Jun 28, 2012
 *      Author: cwrus
 */
#include "RBELib\SetServo.h"
/*
 * This function takes the Student's input, and sends the correct command via serial to the coprocessor.
 *
 * the command must be one-line, contain delimiters, and value must always be 3 chars.
 * this is taken care of automatically, the user simply need call this function with the appropriate pin number and value.
 *
 */
void SetServo(int pin, int value) {
	/*
	 * If the UART1 is not configured properly, call InitAltCom to set it up.
	 */
	InitAltCom(115200);
	if ((UCSR0Bbits._TXEN0 != 1)
			|| (UCSR0Cbits._UMSEL0 != 0)
			|| (UCSR0Cbits._UPM01 != 0)
			|| (UCSR0Cbits._USBS0 != 0)
			|| (UCSR0Cbits._UCSZ0 != 3)
			|| (UCSR0Bbits._UCSZ02 != 0))
			{
					InitAltCom(9600);
			}

	if (value <= 9) {

		dprintfDEBUG_NNL("Setservo");
		dprintfDEBUG_NNL(":");
		dprintfDEBUG_UL(pin);
		dprintfDEBUG_NNL(":");
		//dprintfDEBUG_UL(0);
		//dprintfDEBUG_UL(0);
		dprintfDEBUG_UL(value);
		dprintfDEBUG_NNL("\r\n");

	}

	if ((value >= 10) && (value <= 99)) {

		dprintfDEBUG_NNL("Setservo");
		dprintfDEBUG_NNL(":");
		dprintfDEBUG_UL(pin);
		dprintfDEBUG_NNL(":");
		//dprintfDEBUG_UL(0);
		dprintfDEBUG_UL(value);
		dprintfDEBUG_NNL("\r\n");

	}
	if (value >= 100) {

		dprintfDEBUG_NNL("Setservo");
		dprintfDEBUG_NNL(":");
		dprintfDEBUG_UL(pin);
		dprintfDEBUG_NNL(":");
		dprintfDEBUG_UL(value);
		dprintfDEBUG_NNL("\r\n");

	}
}

/*
 * this function will Initialize the UART1 for communication with the
 * CoProcessor. This function is called automatically whenever it is needed.
 */
void InitAltCom(unsigned long baudrate) {

	unsigned short int baud = CLK / (16 * baudrate) - 1;

	UBRR0bits._w = baud;
	UCSR0Bbits._TXEN0 = 1; //enable transmit

	UCSR0Cbits._UMSEL0 = 0; //Asynchronous Mode
	UCSR0Cbits._UPM01 = 0; //No Parity
	UCSR0Cbits._USBS0 = 0; //1 Stop Bit
	UCSR0Cbits._UCSZ0 = 3; //8bit Character size

	UCSR0Bbits._UCSZ02 = 0;

}
/*
 * this is an alternate function needed to send data to UART1.
 * this should never be called by a student programmer.
 *
 * setCharDebug is identical to putCharDebug except it operates on
 * UART1 instead of 0.
 */
void setCharDebug(char byteToSend) {

	//wait for transmit buffer to clear

	while (!(UCSR0Abits._UDRE0)) {
		//do nothing
	}

	UDR0 = byteToSend;
	while (!(UCSR0Abits._TXC0)) {
		//do nothing
	}
}
/*
 * This is an alternate print function to send a string to UART1
 * this should never be called by a student programmer.
 *
 * this works identical to the normal _NNL function, except it calls
 * the print statement to UART1 instead of 0.
 */
void dprintfDEBUG_NNL(char *str) {

	int x;
	x = 0;
	while (str[x] != '\0') {
		setCharDebug(str[x++]);
	}
}
/*
 * This is an alternate print function to send an integer to UART1.
 * this should never be called by a student programmer.
 *
 * this works identical to the normal _UL function, except it calls
 * the print statement to UART1 instead of 0.
 */
void dprintfDEBUG_UL(UINT32 val) {

	BYTE byteStr[11];
	int x = 0;
	ultoa(val, byteStr);
	// putCharDebug(',');
	while (byteStr[x] != '\0') {
		setCharDebug(byteStr[x++]);
	}

}

/*
void putCharDebug(char byteToSend) {

	//wait for transmit buffer to clear

	while (!(UCSR0Abits._UDRE0)) {
		//do nothing
	}

	UDR0 = byteToSend;
	while (!(UCSR0Abits._TXC0)) {
		//do nothing
	}
}
*/
