/**
 * @file RBELib.h
 *
 * @brief This is a meta-header. It includes all the other header files
 *        that are needed for RBELib as well as some macros.
 *
 * @author Kevin Harrington
 * @date February 21, 2010
 *
 * @author Justin Barrett
 * @date August 23, 2011
 *
 * @author Eric Willcox
 * @date August 19, 2013
 */

#ifndef RBELIB_H_
#define RBELIB_H_

//AVR headers
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

//Macros for input/output
#define OUTPUT 					1
#define INPUT  					  0
#define OFF						    0
#define ON						      1
#if !defined(TRUE)
	#define TRUE 1
	#define FALSE 0
	#define BOOL unsigned char
	#define BYTE unsigned char
	#define UINT32 unsigned long
	#define INT32  long
	#define UINT16 unsigned short int
	#define WORD unsigned short int
  /**
  * @brief For high and low byte.
  */
	typedef union _WORD_VAL
	{
		WORD Val;
		struct
		{
			BYTE LB;
			BYTE HB;
		} byte;
	} WORD_VAL, WORD_BITS;
    /**
  * @brief Bytes of 32-bit value.
  */
	typedef union _UINT32_UNION
	{
		UINT32 Val;
	    BYTE v[4];
	    struct
	    {
	        BYTE LB;
	        BYTE SB;
	        BYTE TB;
	        BYTE FB;
	    } byte;

	} UINT32_UNION;
    /**
  * @brief Bytes of 32-bit value.
  */
	typedef union _LONG_VAL
	{
		long Val;
	    struct
	    {
	        BYTE LB;
	        BYTE HB;
	        BYTE UB;
	        BYTE MB;
	    } byte;
	} LONG_VAL;
#endif

//The rest of the headers in RBELib
#include "reg_structs.h"
#include "ADC.h"
#include "DAC.h"
#include "Debug.h"
#include "USARTDebug.h"
#include "timer.h"
#include "Periph.h"
#include "pot.h"
#include "PID.h"
#include "PORTAdriver.h"
#include "PORTBdriver.h"
#include "PORTCdriver.h"
#include "PORTDdriver.h"
#include "SPI.h"
#include "SetServo.h"


#include "RBEBoard/RBEDefines.h"

#endif /* RBELIB_H_ */
