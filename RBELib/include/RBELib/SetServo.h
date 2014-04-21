/**
 * @file SetServo.h
 *
 * @brief This file allows for using the SerSevo function to move the conveyor and gripper.
 *
 * @author cwrus
 * @date Jun 28, 2012
 * 
 * @author Eric Willcox
 * @date August 19, 2013
 */

#ifndef SETSERVO_H_
#define SETSERVO_H_

#include "RBELib/RBELib.h"
#define CLK 18432000

/**
 * @brief used to initialize UART1 for communication with the coprocessor. It should never be called manually.
 * 
 * @param baudrate Baud rate of the communication line in bps.
 * @return void
 */
void InitAltCom(unsigned long baudrate);

/**
 * @brief Send a char to the coprocessor via UART1.
 * @param byteToSend Value to be sent.
 * @return void
 */
void putCharDebug(char byteToSend);

/**
 * @brief String to send to the coprocessor via UART1 with no new line.
 * @param *str String to send.
 * @return void
 */
void dprintfDEBUG_NNL(char *str);

/**
 * @brief Sends an unsigned long to the coprocessor via UART1.
 * @param val Value to be send.
 * @return void
 */
void dprintfDEBUG_UL(UINT32 val);

/**
 * @brief The communication to set servo values simply.
 * @param Pin Pin number.
 * @param Value Value to set the pin to.
 * @return void
 */
void SetServo(int Pin, int Value);

#endif /* SETSERVO_H_ */
