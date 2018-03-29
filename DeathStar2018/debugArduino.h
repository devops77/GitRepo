/*
 * debugArduino.h
 *
 *  Created on: Mar 25, 2018
 *      Author: BigDaddy
 */

#ifndef DEBUG_ARDUINO_H
#define DEBUG_ARDUINO_H

#define DB_WHERE_AM_I         \
	   Serial.print(millis());     \
	   Serial.print(":[ ");         \
	   Serial.print(__PRETTY_FUNCTION__); \
	   Serial.print(' ');          \
	   Serial.print(__FILE__);     \
	   Serial.print(":");          \
	   Serial.print(__LINE__);     \
	   Serial.print("]  ");

#define ERROR_MSG(str) \
		{\
	   DB_WHERE_AM_I \
	   Serial.println(str);\
		}


#ifdef DEBUG
/*
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
*/


#define DEBUG_PRINT(str)        \
		{\
		DB_WHERE_AM_I  \
		Serial.println(str); \
		}


#define DEBUG_PRINT2(str1, str2)        \
		{\
		DB_WHERE_AM_I  \
		Serial.println(str1, str2); \
		}

#define DB_NAME_VALUE(nstr, vstr) \
		{\
		DB_WHERE_AM_I  \
		Serial.print(nstr); \
		Serial.print("  "); \
		Serial.println(vstr); \
		}

#define DB_NAME_VALUE_HEX(nstr, vstr) \
		{\
		DB_WHERE_AM_I  \
		Serial.print(nstr); \
		Serial.print("  "); \
		Serial.println(vstr,HEX); \
		}

#else  // not debug
#define DEBUG_PRINT(str)

#define DEBUG_PRINT2(str1, str2)

#define DB_NAME_VALUE(nstr, vstr)

#define DB_NAME_VALUE_HEX(nstr, vstr)


#endif /* DEBUG */

#endif /* DEBUG_ARDUINO_H */
