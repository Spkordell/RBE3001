/**
 * @file SPI.h
 *
 * @brief The header file and function prototypes for the SPI.
 *
 * @bug Some SS lines may need to be toggled low -> high -> low (or high -> low -> high) due to some bug with the AVR.  
 *When enabling/disabling SS lines, toggle them to makes sure that they work if you encounter any problems.
 *
 * @author kamiro87
 * @date August 31, 2010
 *
 * @author Justin Barrett
 * @date August 23, 2011 
 * @author Eric Willcox
 * @date August 20, 2013
 */

#ifndef SPI_H_
#define SPI_H_

/**
 * @brief Initializes the SPI bus for a standard configuration.
 *
 * @return void
 *
 * @todo Create the function that will allow you to initialize the SPI.
 */
void GenericSPIInit(void);

/**
 * @brief Checks to see that the SPI is able to transmit and transmits
 *        a byte without changing any other configurations.
 *
 * @param data   The byte to send down the SPI bus.
 * @return value  The byte shifted in during transmit (SPI MUST send AND receive data, even if either is junk data).
 *
 * @todo Make a function that will send a byte of data through the SPI.
 */
BYTE SPITransceive(BYTE data);

#endif /* SPI_H_ */
