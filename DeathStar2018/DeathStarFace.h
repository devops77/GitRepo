/*
 * DeathStarFace.h
 *
 *  Created on: Apr 4, 2018
 *      Author: BigDaddy
 */

#ifndef DEATHSTARFACE_H_
#define DEATHSTARFACE_H_

#include "SoundBoard.h"

#include "Actor.h"


class DeathStarFace: public Actor {
private:
	Adafruit_NeoPixel* pLightStrip;
	SoundBoard* pMySoundBoard;


public:
	DeathStarFace();
	virtual ~DeathStarFace();

	/**
	** set things up
	*/
	void setUp(Adafruit_NeoPixel* newRing, SoundBoard* pMySoundBoard);

  /**
   * update the Neopixels to show new settings
   */
  void updateLights();
  /**
   * start play  sound explode sound
   */
  void startPlayExplodeSound();

/*
   * end trigger (not sound)
   */
  void endPlayExplodeSound();




  /**
  ** will cause all lights to fade
  **/
  int fadeLights(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);

  
  void setAllLights(uint32_t color);

  void setLight(uint32_t i, uint32_t color);

  void setRandomLight(uint8_t minId, uint8_t maxId, uint32_t color);

};

#endif /* DEATHSTARFACE_H_ */
