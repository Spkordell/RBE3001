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
  * @file Debug.h
 *
 * @brief Debug commands for the RBE 3001 board.
 *
 * @author Neuron Robotics, LLC
 * @date 2009
 *
 * @author Eric Willcox
 * @date August 19, 2013
 */

#ifndef DEBUG_H_
#define DEBUG_H_
 /**
 * @brief enable printing (Defaults to enabled).
 *
 * @return void
 *
 */
void enableDebug(void);

  /**
 * @brief disable printing (Defaults to enabled).
 *
 * @return void
 *
 */
void disableDebug(void);

  /**
 * @brief Prints a given value as a 16 bit hex value.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define prHEX(A) printfDEBUG_BYTE(GetHighNib(A>>8));printfDEBUG_BYTE(GetLowNib(A>>8));printfDEBUG_BYTE(GetHighNib(A&0x00ff));printfDEBUG_BYTE(GetLowNib(A&0x00ff))

  /**
 * @brief Print the ASCII character of a float with no new line.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define p_fl(A) printfDEBUG_FL(A)

  /**
 * @brief Prints the ASCII character of an unsigned long/int with no new line.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define p_ul(A) printfDEBUG_UL(A)

  /**
 * @brief Prints the ASCII of a signed long/int with no new line.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define p_sl(A) printfDEBUG_SL(A)

  /**
 * @brief Prints the null terminated string with no new line.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define print(A) printfDEBUG_NNL(A)

  /**
 * @brief Prints the null terminated string with a newline inserted at the beginning of the string.
 *
 * @param A Value to print.
 * @return void
 *
 */
#define println(A) printfDEBUG(A)

  /**
 * @brief Sends the character to the serial port if it is ASCII. If it is not ASCII, it is converted to a character then sent
 *
 * @param b Value to send to the serial port.
 * @return void
 *
 */
void printfDEBUG_BYTE(char b);

  /**
 * @brief Prints the null terminated string with a newline inserted at the beginning of the string.
 *
 * @param *str String to print.
 * @return void
 *
 */
void printfDEBUG(char *str);

  /**
 * @brief print the null terminated string with no new lines
 *
 * @param *str String to print.
 * @return void
 *
 */
void printfDEBUG_NNL(char *str);

  /**
 * @brief Prints the ASCII of an unsigned long/int with no new line.
 *
 * @param val Value to print.
 * @return void
 *
 */
void printfDEBUG_UL(unsigned long val);

  /**
 * @brief print the ASCII of a signed long/int with no new line.
 *
 * @param val Value to print.
 * @return void
 *
 */
void printfDEBUG_SL(long val);

  /**
 * @brief Convert a long into an ASCII string and place the string into the buffer.
 *
 * @param Value Value to convert.
 * @param Buffer Where to store the conversion.
 * @return void
 *
 */
void ultoa(unsigned long Value, unsigned char* Buffer);

  /**
 * @brief print all the bytes in a byte array. The length of the array must be correct
 *
 * @param stream Array to be printed.
 * @param len Length of the array.
 * @return void
 *
 */
void printByteArray(unsigned char * stream,unsigned short int len);

  /**
 * @brief   convert a float into an ASCII string and place the string into the buffer.
 *
 * @param f Value to be converted.
 * @param outbuf Buffer.
 * @return void
 *
 */
void ftoa(float f, char * outbuf);

  /**
 * @brief print the ASCII of a float with no new line.
 *
 * @param f Value to be printed.
 * @return void
 */
void printfDEBUG_FL(float f);

  /**
 * @brief Gets the low nibble from a byte.
 *
 * @param b Value to get the low nibble from.
 * @return The lower 4 bits of a byte.
 */
char GetLowNib(unsigned char b);

  /**
 * @brief Gets the high nibble from a byte.
 *
 * @param b Value to get the high nibble from.
 * @return The upper 4 bits of a byte.
 *
 */
char GetHighNib(unsigned char b);

#endif /* DEBUG_H_ */
