/**
 * @file PORTAdriver.h
 *
 * @brief The header file and function prototypes for PORTA.
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

#ifndef PORTADRIVER_H_
#define PORTADRIVER_H_

/**
 * @brief Sets the direction (Input/Output) of the specified pin on PORTA.
 *
 * @param direction   The desired direction for the pin (Input or Output).
 * @param pin           The pin on PORTA to set the direction of.
 * @return void
 */
void SetPORTADDR(unsigned char direction, unsigned char pin);

/**
 * @brief Returns the value on the specified pin of PORTA.
 *
 * @param pin     The pin on PORTA to retrieve the value of.
 * @return value  The value of the specified pin on PORTA.
 */
unsigned char GetPORTAPinValue(unsigned char pin);

/**
 * @brief Sets the value on the specified pin of PORTA.
 *
 * @param pin    The pin on PORTA to set the value of.
 * @param value  The value to set the specified pin on PORTA to.
 * @return void
 */
void SetPORTAPinValue(unsigned char pin, unsigned char value);

#endif /* PORTADRIVER_H_ */
