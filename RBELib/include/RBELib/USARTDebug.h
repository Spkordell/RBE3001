/**
 * @file USARTDebug.h
 *
 * @brief The header file and function prototypes for the USART.
 *
 * @author Kevin Harrington
 * @date August 20, 2010
 *
 * @author Justin Barrett
 * @date August 25, 2011
 *
 * @author Eric Willcox
 * @date August 20, 2013
 */

#ifndef USART_H_
#define USART_H_

#define DEFAULT_BAUD 115200

/**
 * @brief Initializes USART1 as a print terminal to the PC. This function
 *        must check the incoming baudrate against the valid baudrates
 *        from the data-sheet. If the baudrate is invalid, then the
 *        DEFAULT_BAUD (see above) must be used instead.
 *
 * @param baudrate  The desired baudrate to set for USART1.
 * @return void
 * 
 * @todo Create the function that will initialize the USART for debugging use.
 */
void DebugUSARTInit(unsigned long baudrate);

/**
 * @brief Sends one byte to the USART1 Tx pin (Transmits one byte).
 *        PREREQUISITE: DebugUSARTInit must be called first.
 *
 * @param byteToSend  The byte that is to be transmitted through USART1.
 * @return void
 *
 * @todo Make the function that will put a character on the USART line.
 */
void putCharDebug(char byteToSend);

/**
 * @brief Recieves one byte of data from the serial port (from the PC).
 *
 * @return charRec Character that was received on the USART.
 *
 * @todo Make the function that will listen for input on the USART.
 */
unsigned char USART_Receive(void);

#endif /* USART_H_ */
