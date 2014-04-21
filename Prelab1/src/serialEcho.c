/*
 * serialEcho.c
 *
 *  Created on: Jan 19, 2014
 *      Author: Steven Kordell
 */

#include "main.h"

/*
 * Echos through the UART any characters that are received. Doesn't return from call.
 */
void echoSerialData() {
	DebugUSARTInit(DEFAULT_BAUD);
	while(1) {
		putCharDebug(USART_Receive());
	}
}
