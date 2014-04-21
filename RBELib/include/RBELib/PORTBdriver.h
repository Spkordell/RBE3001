/**
 * @file PORTBdriver.h
 *
 * @brief The header file and function prototypes for PORTB.
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

#ifndef PORTBDRIVER_H_
#define PORTBDRIVER_H_

/**
 * @brief Sets the direction (Input/Output) of the specified pin on PORTB.
 *
 * @param direction   The desired direction for the pin (Input or Output).
 * @param pin           The pin on PORTB to set the direction of.
 * @return void
 */
void SetPORTBDDR(unsigned char direction, unsigned char pin);

/**
 * @brief Returns the value on the specified pin of PORTB.
 *
 * @param pin     The pin on PORTB to retrieve the value of.
 * @return value  The value of the specified pin on PORTB.
 */
unsigned char GetPORTBPinValue(unsigned char pin);

/**
 * @brief Sets the value on the specified pin of PORTB.
 *
 * @param pin    The pin on PORTB to set the value of.
 * @param value  The value to set the specified pin on PORTB to.
 * @return void
 */
void SetPORTBPinValue(unsigned char pin, unsigned char value);

#endif /* PORTBDRIVER_H_ */
