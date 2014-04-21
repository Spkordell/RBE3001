/**
 * @file PORTDdriver.h
 *
 * @brief The header file and function prototypes for PORTD.
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

#ifndef PORTDDRIVER_H_
#define PORTDDRIVER_H_

/**
 * @brief Sets the direction (Input/Output) of the specified pin on PORTD.
 *
 * @param direction  The desired direction for the pin (Input or Output).
 * @param pin        The pin on PORTD to set the direction of.
 * @return void
 */
void SetPORTDDDR(unsigned char direction, unsigned char pin);

/**
 * @brief Returns the value on the specified pin of PORTD.
 *
 * @param pin    The pin on PORTD to retrieve the value of.
 * @return value  The value of the specified pin on PORTD.
 */
unsigned char GetPORTDPinValue(unsigned char pin);

/**
 * @brief Sets the value on the specified pin of PORTD.
 *
 * @param pin    The pin on PORTD to set the value of.
 * @param value  The value to set the specified pin on PORTD to.
 * @return void
 */
void SetPORTDPinValue(unsigned char pin, unsigned char value);

#endif /* PORTDDRIVER_H_ */
