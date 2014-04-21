/**
 * @file PID.h
 *
 * @brief The header file for PID constants and calculations.
 * @details Sets the PID constants and calculate the PID value.
 * @author Eric Willcox
 * @date August 17 2013
 */

#ifndef PID_H_
#define PID_H_

/**
 * @brief PID constants.
 * @details Obtain value using:
 * @code pidConst.Kp_H; @endcode for the value desired.
 */
typedef struct {
  /**
   * @brief Upper link Kp.
   */
  float Kp_H;
  /**
   * @brief Upper link Ki.
   */
  float Ki_H;
  /**
   * @brief Upper link Kd.
   */
  float Kd_H;
  /**
   * @brief Lower link Kp.
   */
  float Kp_L;
  /**
   * @brief Lower link Ki.
   */
  float Ki_L;
  /**
   * @brief Lower link Kd.
   */
  float Kd_L;
} pidConst;

/**
* @brief Declaration for use in other files.
*/
extern pidConst pidConsts;

/** 
 * @brief Sets the Kp, Ki, and Kd values for 1 link.
 * @details to set the values, use the following style
 * @code {.h}
 *  pidConst.Kp = 1.3; 
 * @endcode
 * @param link The link you want to set the values for (H or L).
 * @param Kp Proportional value.
 * @param Ki Integral value.
 * @param Kd Derivative value.
 * @return void
 *
 * @todo Create a function to the the PID constants for a given link/
 */
void setConst(unsigned char link, float Kp, float Ki, float Kd);

/** 
 * @brief Calculate the PID value.
 * @param setPoint The desired position of the link.
 * @param actPos The current position of the link.
 * @param  Kp Proportional value.
 * @param Ki Integral value.
 * @param Kd Derivative value.
 * @return void
 *
 * @todo Make a function to calculate the PID value for a link.
 */
int calcPID(int setPoint, int actPos, float Kp, float Ki, float Kd);

#endif /* PERIPH_H_ */
