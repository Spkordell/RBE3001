/*
 * kinematics.c
 *
 *  Created on: Feb 5, 2014
 *      Author: Steven Kordell
 */


#include "main.h"

void calcFPK(float* x, float* y, float lowLinkAngle, float highLinkAngle) {
	*x = LOW_LINK_LENGTH*cos(lowLinkAngle*RADIANS_PER_DEGREE)+HIGH_LINK_LENGTH*cos((lowLinkAngle+highLinkAngle)*RADIANS_PER_DEGREE);
	*y = LOW_LINK_LENGTH*sin(lowLinkAngle*RADIANS_PER_DEGREE)+HIGH_LINK_LENGTH*sin((lowLinkAngle+highLinkAngle)*RADIANS_PER_DEGREE);
}

void calcIPK(float* lowLinkAngle, float* highLinkAngle, float x, float y) {
	*highLinkAngle = acos((x*x+y*y-LOW_LINK_LENGTH*LOW_LINK_LENGTH-HIGH_LINK_LENGTH*HIGH_LINK_LENGTH)/(2*LOW_LINK_LENGTH*HIGH_LINK_LENGTH)); //Note, there is a more accurate way to do this using a half-angle formula and atan instead, however, the resulting formula is more computationally intensive
	//*highLinkAngle = 2*atan(sqrt(((LOW_LINK_LENGTH+HIGH_LINK_LENGTH)*(LOW_LINK_LENGTH+HIGH_LINK_LENGTH) - (x*x+y*y))/((x*x+y*y)-(LOW_LINK_LENGTH-HIGH_LINK_LENGTH)*(LOW_LINK_LENGTH-HIGH_LINK_LENGTH))));
	*lowLinkAngle = *highLinkAngle - atan2(-y,x); //alternativly another solution exists where second term is atan2(HIGH_LINK_LENGTH*sin(HIGH_LINK_ANGLE),LOW_LINK_LENGTH+HIGH_LINK_LENGTH*cos(HIGH_LINK_ANGLE))
	/*
	p_fl(*lowLinkAngle);
	print("\t");
	p_fl(*highLinkAngle);
	println("");
	*/
	*highLinkAngle*=DEGREES_PER_RADIAN;
	*lowLinkAngle*=DEGREES_PER_RADIAN;


}
