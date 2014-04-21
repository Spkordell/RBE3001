/**
 * @file timer.h
 *
 * @brief The header file and function prototypes for Timers 0-2.
 *
 * @author Justin Barrett
 * @date August 25, 2011
 *
 * @author Eric Willcox
 * @date August 20, 2013
 */

#ifndef TIMER_H_
#define TIMER_H_
/**
 * Runs the timer in Normal mode.
 */
#define NORMAL     0
/**
 * Runs the timer in Clear Timer on Compare (CTC) mode.
 */
#define CTC		   1

/**
 * @brief Initializes the specified timer in the specified mode. This
 *        header file provides #defines for NORMAL operation mode and
 *        CTC operation mode, however there are many more modes of operation
 *        for the Timers that can be experimented with.
 *
 * @param number  The number of the timer to be initialized (0-2).
 * @param mode    The mode to initialize the specified timer in
 *                                    (see defines above).
 * @param comp    Only used in CTC mode. The value that the
 *                                    timer counts to before it triggers an interrupt
 *                                    and resets.
 * @return void
 *
 * @todo Create a function that initializes the desired timer in a given mode and set the compare value.
 */
void InitTimer(unsigned char number, unsigned char mode, unsigned short int comp);

/**
 * @brief Only used when the specified timer is in CTC mode. Changes
 *        the value of the comparison register (OCRnA) to the new specified
 *        value.
 *
 * @param number  The number of the timer to change (0-2).
 * @param comp    The value to set the OCRnA register to.
 * @return void
 *
 * @todo Create a function that will set the compare value for the given time.
 */
void setCompValue(unsigned char number, unsigned short int comp);

#endif /* TIMER_H_ */
