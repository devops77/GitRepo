
#include <stdint.h>
#include "Actor.h"

#ifndef TIEFIGHTER_H
#define TIEFIGHTER_H

/**
  * class TieFighter
  *
*/

#include "SoundBoard.h"

#define TieFighterNumberOfLightsInner 5
#define TieFighterNumberOfLightsOuter 5





class TieFighter:  public Actor
{
private:
	// lights for inner explosion
	uint8_t  innerLightsIds  [TieFighterNumberOfLightsInner];
	uint8_t  outerLightIds[TieFighterNumberOfLightsOuter];
	uint8_t targetNumber;
	Adafruit_NeoPixel* pLightStrip;
	uint8_t myLaserPin;
	uint8_t myHitSwitchPin;
	bool myIsAlive;
	SoundBoard* pMySoundBoard;

	void initAttributes () ;



public:

	/**
	* Empty Constructor
	*/
	TieFighter();   // must give the target number



  /**
   * Empty Destructor
   */
  virtual ~TieFighter ();


  void setUp(uint8_t newTargetNumber, Adafruit_NeoPixel* newStrip, SoundBoard* pSoundBoard);

  bool getTargetUp();
  bool getIsAlive();
  void setIsAlive(bool);

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
   * start play  sound shoot sound
   */
  void startPlayLaserSound();


  /*
   * end trigger (not sound)
   */
  void endPlayLaserSound();

  /**
   * start play  sound shoot sound
   */
  void startPlayExplodeSound();



  /*
   * end trigger (not sound)
   */
  void endPlayExplodeSound();



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
  uint8_t fadeLightInnerNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);

  /**
   * fade outer lights to newvalue will not show at this time
   */
  uint8_t fadeLightOuterNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);

  /**
   * will set the PWM output pin duty cycle 255 full brightness, 0 -is off
   */
  void setLaserBrightness(uint8_t brightness);

  uint8_t getTargetNumber();


};

#endif // TIEFIGHTER_H
