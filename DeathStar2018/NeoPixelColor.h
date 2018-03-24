
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
   * @param  Delta
   * @param  min
   * @param  max
   */
  NeoPixelColor shiftColor (uint32_t Delta, uint32_t min = 0x000000, uint32_t max = 0xffffff);



  /**
   * call coolor shift for subset of  ligts in a given noepixel object
   * 
   * @param  lights
   * @param  lightIds
   * @param  numberOfLights
   * @param  delta
   * @param  min
   * @param  max
   */
  void colorShiftSetOfLights (Adafruit_NeoPixel & lights, uint8_t  lightIds, uint8_t numberOfLights, uint32_t delta, uint32_t min = 0x000000, uint32_t max = 0xffffff);


  /**
   * set a sub group of lights
   * @param  lights li
   * @param  lightIds
   * @param  color
   */
  void setLightsToSameColor (Adafruit_NeoPixel & lights, uint8_t  lightIds, uint32_t color);


};

#endif // NEOPIXELCOLOR_H
