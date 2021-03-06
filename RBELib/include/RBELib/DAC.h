/**
 * @file DAC.h
 *
 * @brief The header file and function prototypes for the DAC.
 * @details Use these functions to control the behaviour of the DAC.
 * @author Eric Willcox
 * @date August 21,  2013
 */

#ifndef DAC_H_
#define DAC_H_

/** 
 * @brief Set the DAC to the given value on the chosen channel.
 * @param  DACn The channel that you want to set.
 * @param SPIVal The value you want to set it to.
 * @return void
 *
 * @todo Make the function that is able to set the DAC to a given value from 0 - 4095.
 */
void setDAC(unsigned char DACn, unsigned int SPIVal);

#endif /* DAC_H_ */
