/**
 * @file PORTCdriver.h
 *
 * @brief The header file and function prototypes for PORTC.
 *
 * @author Kevin Harrington
 * @date August 30, 2010
 *
 * @author Justin Barrett
 * @date August 23, 2011
 *
 * @author Eric Willcox
 * @date August 19, 2013
 */

#ifndef PORTCDRIVER_H_
#define PORTCDRIVER_H_

/**
 * @brief Sets the direction (Input/Output) of the specified pin on PORTC.
 *
 * @param direction  The desired direction for the pin (Input or Output).
 * @param pin           The pin on PORTC to set the direction of.
 * @return void
 */
void SetPORTCDDR(unsigned char direction, unsigned char pin);

/**
 * @brief Returns the value on the specified pin of PORTC.
 *
 * @param pin     The pin on PORTC to retrieve the value of.
 * @return value  The value of the specified pin on PORTC.
 */
unsigned char GetPORTCPinValue(unsigned char pin);

/**
 * @brief Sets the value on the specified pin of PORTC.
 *
 * @param pin    The pin on PORTC to set the value of.
 * @param value  The value to set the specified pin on PORTC to.
 * @return void
 */
void SetPORTCPinValue(unsigned char pin, unsigned char value);

#endif /* PORTCDRIVER_H_ */
