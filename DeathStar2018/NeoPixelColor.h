
#ifndef NEOPIXELCOLOR_H
#define NEOPIXELCOLOR_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


/**
  * class NeoPixelColor
  * 
  */

class NeoPixelColor
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  NeoPixelColor ();

  /**
   * Empty Destructor
   */
  virtual ~NeoPixelColor ();


  static void splitColor(uint32_t input, int & red, int & green, int & blue );

  static uint8_t shiftOneColor(int start, int delta, int min, int max);


  /**
   * use to fade colort from one to an other for a give delat
   * My collor + Delta = return value
   *    Check for 255 and -1 wrap
   * 
   * how AdaFruit does it
   * Convert separate R,G,B into packed 32-bit RGB color.
   * Packed format is always RGB, regardless of LED strand color order.
   * 	uint32_t Adafruit_NeoPixel::Color(uint8_t r, uint8_t g, uint8_t b)
   * 	{
   * 		return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
   * 	}
   * 
   * 
   * @return NeoPixelColor
   * @param  Delta r g b
   * @param  min
   * @param  max
   */
  static uint32_t shiftColor(int redDelta, int greenDelta, int blueDelta, uint32_t start, uint32_t min, uint32_t max);



};

#endif // NEOPIXELCOLOR_H
