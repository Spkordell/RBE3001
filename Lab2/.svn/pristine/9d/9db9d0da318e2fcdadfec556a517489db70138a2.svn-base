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

#define SUM_ERROR_MAX 100

/**
 * @brief PID constants.
 * @details Obtain value using:
 * @code pidConst.Kp_H; @endcode for the value desired.
 */
typedef struct {
  volatile float Kp_H;
  volatile float Ki_H;
  volatile float Kd_H;
  volatile float Kp_L;
  volatile float Ki_L;
  volatile float Kd_L;
  volatile float lastError_H;
  volatile float lastError_L;
  volatile float sumError_H;
  volatile float sumError_L;
  volatile float dt;
} PidConst;

/**
* @brief Declaration for use in other files.
*/
extern PidConst pidConst;

void initPID(float dt);
void startPID();
void setConst(unsigned char link, float Kp, float Ki, float Kd);
void calcPID(unsigned char link, int setPoint, int actPos);


#endif /* PID_H_ */
