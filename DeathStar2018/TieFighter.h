
#include <stdint.h>
#include "Actor.h"

#ifndef TIEFIGHTER_H
#define TIEFIGHTER_H

/**
  * class TieFighter
  *
*/
#define TieFighterNumberOfLightsInner 2
#define TieFighterNumberOfLightsOuter 6




class TieFighter:  public Actor
{
private:
	// lights for inner explosion
	uint8_t  innerLightsIds  [TieFighterNumberOfLightsInner];
	uint8_t  outerLightIds[TieFighterNumberOfLightsOuter];
	uint8_t targetNumber;
	Adafruit_NeoPixel* pLightStrip;




	void initAttributes () ;



public:

	/**
	* Empty Constructor
	*/
	TieFighter ();   // must give the target number


	TieFighter (uint8_t newTargetNumber, Adafruit_NeoPixel* newStrip);

  /**
   * Empty Destructor
   */
  virtual ~TieFighter ();

  /**
   * to do: check for more than array size
   * @param  index zerobased index into arry of lights
   * @param  lightId zero based possition in NeoPixel  strip or circle
   */
  void setLightIdsOuter (uint8_t index, uint8_t lightId);


  /**
   * to do: check for more than array size
   * @param  index zerobased index into arry of lights
   * @param  lightId zero based possition in NeoPixel  strip or circle
   */
  void setLightIdsInner (uint8_t index, uint8_t lightId);

  /**
   * update the Neopixels to show new settings
   */
  void updateLights();

  /**
   * pla a sound
   */
  void playSound(int pinNumber);

  /**
   * this is call as part of main loop
   * Switch on script then call script run
   */
  void run ();

  /**
   * set inner lights to newvalue will not show at this time
   */
  void setLigntInnerNoShow(uint32_t newColor);

  /**
   * set outer lights to newvalue will not show at this time
   */
  void setLigntOuterNoShow(uint32_t newColor);

  /**
   * fade inner lights to newvalue will not show at this time
   */
  void fadeLightInnerNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);

  /**
   * fade outer lights to newvalue will not show at this time
   */
  void fadeLightOuterNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);




};

#endif // TIEFIGHTER_H
