/*
* main.c
*
* Created on: Aug 27, 2012
* Author: joest
*/
#include "main.h"

void initializations(){
	initGlobals();
	initPB();
}

int main() {
	initializations();
	while(1){
		blinkAll(100);
	}
	return 0;
}
