/*
 * myatof.h
 *
 *  Created on: Mar 3, 2014
 *      Author: cbwallepstein
 */

/*
 *
 * Because of incompatibilities with RBELIb, it was necessary to include the atof function separately. This declaration is nearly identical to the one found in stdlib.c
 *
 */

#ifndef MYATOF_H_
#define MYATOF_H_

#include "main.h"

double myatof(char s[]);

#endif /* MYATOF_H_ */
