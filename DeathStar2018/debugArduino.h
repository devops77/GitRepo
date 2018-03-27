/*
 * debugArduino.h
 *
 *  Created on: Mar 25, 2018
 *      Author: BigDaddy
 */

#ifndef DEBUGARDUINO_H_
#define DEBUGARDUINO_H_


#define DEBUG_PRINT(str)        \
   Serial.print(millis());     \
   Serial.print(":[ ");         \
   Serial.print(__PRETTY_FUNCTION__); \
   Serial.print(' ');          \
   Serial.print(__FILE__);     \
   Serial.print(":");          \
   Serial.print(__LINE__);     \
   Serial.print("]  ");          \
   Serial.println(str);

#define DEBUG_PRINT2(str1, str2)        \
   Serial.print(millis());     \
   Serial.print(":[ ");         \
   Serial.print(__PRETTY_FUNCTION__); \
   Serial.print(' ');          \
   Serial.print(__FILE__);     \
   Serial.print(":");          \
   Serial.print(__LINE__);     \
   Serial.print("]  ");          \
   Serial.println(str1, str2);



#endif /* DEBUGARDUINO_H_ */
