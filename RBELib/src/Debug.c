/**
 *
 * Copyright 2009 Neuron Robotics, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include "RBELib/RBELib.h"
#if !defined(RBE3002)
static BOOL DebugFlag=TRUE;

void enableDebug(void){
	DebugFlag=TRUE;
}
void disableDebug(void){
	DebugFlag=FALSE;
}

const char AsciiHex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char GetLowNib(BYTE b){
	return AsciiHex[b&0x0f];
}
char GetHighNib(BYTE b){
	return AsciiHex[((b&0xF0)>>4)];
}

void printfDEBUG(char *str){

	if (!DebugFlag){
		return;
	}
	int x;
	x=0;
	 putCharDebug('\n');
	 putCharDebug('\r');
	while(str[x]!='\0'){
		 putCharDebug(str[x++]);
	}

}
void printfDEBUG_BYTE(char b){

	if (!DebugFlag){
			return;
	}
	 putCharDebug(b);

}
void printfDEBUG_NNL(char *str)
{

	if (!DebugFlag){
		return;
	}
	int x;
	x=0;
	while(str[x]!='\0'){
		 putCharDebug(str[x++]);
	}


}
void printfDEBUG_UL(UINT32 val){

	if (!DebugFlag){
		return;
	}
	BYTE byteStr[11];
	int x=0;
	ultoa(val,byteStr);
	// putCharDebug(',');
	while(byteStr[x] != '\0'){
		 putCharDebug(byteStr[x++]);
	}

}

void printfDEBUG_SL(INT32 val){

	if (!DebugFlag){
		return;
	}
	BYTE byteStr[11];
	int x=0;
	if (val<0){
		val *=-1;
		putCharDebug('-');
	}
	ultoa(val,byteStr);
	// putCharDebug(',');
	while(byteStr[x] != '\0'){
		putCharDebug(byteStr[x++]);
	}

}
/*
void printfDEBUG_FL(float f){
	if (!DebugFlag){
		return;
	}
	INT32 upper = (INT32)f;
	INT32 shift =(INT32)(f*1000);
	INT32 clip  = upper*1000;
	printfDEBUG_SL(upper);
	putCharDebug('.');
	INT32 dec =shift-clip;
	if (dec<0)
		dec*=-1;
	if(dec<100)
		putCharDebug('0');
	if(dec<10)
		putCharDebug('0');
	printfDEBUG_UL(dec);
}*/

void printfDEBUG_FL(float f){
    if (!DebugFlag){
        return;
    }
    if(f>-1 && f<0){
        putCharDebug('-');
    }
    INT32 upper = (INT32)f;
    INT32 shift =(INT32)(f*1000);
    INT32 clip = upper*1000;
    printfDEBUG_SL(upper);
    putCharDebug('.');
    INT32 dec =shift-clip;
    if (dec<0)
    dec*=-1;
    if(dec<100)
    putCharDebug('0');
    if(dec<10)
    putCharDebug('0');
    printfDEBUG_UL(dec);
}


void printByteArray(BYTE * stream,UINT16 len){
	UINT16 i;
	printfDEBUG_NNL(" Stream: size=");
	printfDEBUG_UL(len);
	printfDEBUG_NNL(" [");
	for (i=0;i<len;i++){
		printfDEBUG_UL(stream[i]);
		if (i<(len-1))
			printfDEBUG_BYTE(',');
	}
	printfDEBUG_NNL("]");
}

void ultoa(UINT32 Value, BYTE* Buffer)
{
	if (!DebugFlag){
		return;
	}
	BYTE i;
	UINT32 Digit;
	UINT32 Divisor;
	BOOL Printed = FALSE;

	if(Value)
	{
		for(i = 0, Divisor = 1000000000; i < 10; i++)
		{
			Digit = Value/Divisor;
			if(Digit || Printed)
			{
				*Buffer++ = '0' + Digit;
				Value -= Digit*Divisor;
				Printed = TRUE;
			}
			Divisor /= 10;
		}
	}
	else
	{
		*Buffer++ = '0';
	}

	*Buffer = 0;
}

#endif
