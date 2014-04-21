/*
 * USARTDebug.c
 *
 *  Created on: Jan 20, 2014
 *      Author: Steven Kordell
 */


#include "main.h"

void DebugUSARTInit(unsigned long baudrate) {
	//Ensure a valid baudrate was supplied, else use the default baud
	const long bauds[14] = {110, 150, 300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600};
	unsigned long baud = DEFAULT_BAUD;
	for(int i = 0; i < 13; i++) {
		if(baudrate == bauds[i]) {
			baud = bauds[i];
			break;
		}
	}

	// Set baud rate
	UBRR1H = (F_CPU / (16 * baud) - 1) >> 8;
	UBRR1L = (F_CPU / (16 * baud) - 1);
	//Enable receiver and transmitter
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	// Set frame format: 8data, 1stop bit
	UCSR1C = (1<<USBS1)|(3<<UCSZ10);
}

void putCharDebug(char byteToSend) {
	/* Wait for empty transmit buffer */
	while (!( UCSR1A & (1<<UDRE1)));
	/* Put data into buffer, sends the data */
	UDR1 = byteToSend;
}

unsigned char USART_Receive(void) {
	/* Wait for data to be received */
	while (!(UCSR1A & (1<<RXC1)));
	/* Get and return received data from buffer */
	return UDR1;
}
