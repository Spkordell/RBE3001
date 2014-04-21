/**
 * @file ADC.h
 *
 * @brief The header file and function prototypes for the ADC.
 * @details For single ended conversion, the ADC value an be found from the voltage using:
 * @f[ \frac {V_{in} * 1024}{V_{ref}} @f]
 * @author Kevin Harrington
 * @date February 11, 2010
 *
 * @author Justin Barrett
 * @date August 23, 2011
 *
 * @author Eric Willcox
 * @date August 19, 2013
 */

#ifndef ADC_H_
#define ADC_H_

/**
 * @brief Initializes one and only one channel of the ADC.
 *
 * @param channel  The ADC channel to initialize.
 * @return void
 *
 * @todo Create the corresponding function to initialize the ADC using the channel parameter.  Pages: 233 - 252
 */
void InitADC(unsigned char channel);

/**
 * @brief Disables ADC functionality from one and only one pin.
 *
 * @param channel  The ADC channel to disable.
 * @return void
 *
 * @todo Create the corresponding function to clear the last ADC calculation register.  Pages: 233 - 252
 */
void ClearADC(unsigned char channel);

/**
 * @brief Run a conversion on and get the analog value from one ADC channel.
 *
 * @param channel  The ADC channel to run a conversion on.
 * @return unsigned short  value    The 10-bit value returned by the ADC conversion.
 *
 * @todo Create the corresponding function to obtain the value of the last calculation.  Pages: 233 - 252
 */
unsigned short GetADC(unsigned char channel);

#endif /* ADC_H_ */
