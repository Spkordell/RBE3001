/**
 * @file Periph.h
 *
 * @brief The header file and function prototypes for the peripherals (IR, encoder and accelerometer).
 * @details Each of these functions is for controlling the peripheral devices of the arm.
 * @author Eric Willcox
 * @date August 21,  2013
 */

#ifndef PERIPH_H_
#define PERIPH_H_

/** 
 * @brief Find the acceleration in the given axis (X, Y, Z).
 * @details Because it takes in an unsigned char, feel free to use something like
 *  'X', 'Y', 'Z' (characters) instead of numbers if you prefer.
 * @param  axis The axis that you want to get the measurement of (x, y, z).
 * @return gVal Value of  acceleration.
 *
 * @todo Create a function that is able to find the acceleration of a given axis.
 */
int getAccel(unsigned char axis);

/** 
 * @brief Retrieve the ADC value of the IR sensor.
 * @param  port The port that the IR sensor is on.
 * @return value ADC count of the IR sensor.
 *
 * @todo Make a function that is able to get the ADC value of the IR sensor.
 */
int readIR(int port);

/** 
 * @brief Covert the ADC value of the IR sensor into a distance in the unit of your choice.
 * @param  IRVal The ADC reading of the IR sensor.
 * @return dist Distance of the object from the IR sensor in your chosen units.
 *
 * @todo Create a function to find the distance of an object from the IR sensor.
 */
float getDist(int IRVal);

/** 
 * @brief Finds the count of the Encoders and returns it as a 32-bit value.
 * @param  chan Channel that the encoder is on that you would like to read.
 * @return count The current count of the encoder.
 *
 * @todo Make a function to find the encoder counts on a given channel.
 */
 unsigned long encCount(int chan);

#endif /* PERIPH_H_ */
