/**
 * @file pot.h
 *
 * @brief The header file and function prototypes for the potentiometers.
 * @details  Use these functions to read the values from the pots.
 * @author Eric Willcox
 * @date August 17 2013
 */

#ifndef POT_H_
#define POT_H_

/** 
 * @brief Find the ADC value of the given potentiometer.
 * @param  pot The pot to get the value of.
 * @return adcVal Value of  potentiometer.
 *
 * @todo Create a function to get the ADC value of the potentiometer.  
 */
int potADC(unsigned char pot);

/** 
 * @brief Find the voltage value of the given potentiometer.
 * @param  pot The pot to get the value of.
 * @return volts Voltage of  potentiometer.
 *
 * @todo Create a function to get the voltage of the potentiometer.  
 */
int potVolts(unsigned char pot);

#endif /* PERIPH_H_ */
