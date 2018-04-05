#define DEBUG
/*
 * DeathStarFace.cpp
 *
 *  Created on: Apr 4, 2018
 *      Author: BigDaddy
 */
#include "global.h"
#include "debugArduino.h"
#include "Sceens.h"
#include "DeathStarFace.h"

DeathStarFace::DeathStarFace() {
	// TODO Auto-generated constructor stub

}

DeathStarFace::~DeathStarFace() {
	// TODO Auto-generated destructor stub
}


void DeathStarFace::setUp(Adafruit_NeoPixel* newStrip)
{
	//DEBUG_PRINT("VentPort::setUp");
	pLightStrip = newStrip;

}
  /**
   * update the Neopixels to show new settings
   */
  void DeathStarFace::updateLights()
  {
	  //DB_NAME_VALUE("VentPort::updateLights", "about to call update");
	  pLightStrip->show();

  }
  /**
   * start play  sound explode sound
   */
  void DeathStarFace::startPlayExplodeSound()
  {
	  digitalWrite(DEATH_STAR_EXPLODE_PIN,LOW);   // must be low for 150 ms
  }

/*
   * end trigger (not sound)
   */
  void DeathStarFace::endPlayExplodeSound()
  {
	  digitalWrite(DEATH_STAR_EXPLODE_PIN,HIGH);   // must be low for 150 ms
  }




  /**
  ** will cause all lights to fade
  **/
  void DeathStarFace::fadeLights(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
  {

	for( int i=0; i<FaceNumberOfLights; i++ )
	{
		// get
		uint32_t start = pLightStrip->getPixelColor(i);
		// adjust
		uint32_t newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue, start, min, max);

		//save
		pLightStrip->setPixelColor(i, newColor);
	}

  }

  /**
   * set all the lights in the vent port to a color
   * used to clear and throb
   */
  void DeathStarFace::setAllLights(uint32_t color)
  {

		for( int i=0; i<FaceNumberOfLights; i++ )
		{
			pLightStrip->setPixelColor(i, color);
		}
		pLightStrip->show();
  }


  void DeathStarFace::setLight(uint32_t i, uint32_t color)
  {
//	  DB_NAME_VALUE("set i ", i);
//	  DB_NAME_VALUE("set C ", color);
	  pLightStrip->setPixelColor(i, color);
  }

/**
 * fade inner lights to newvalue will not show at this time
 */
	uint8_t TieFighter::fadeLightInnerNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
	{

		uint8_t changed = 0; // assume nothing changed

		for( int i=0; i<TieFighterNumberOfLightsInner; i++ )
		{
			// get
			uint32_t start = pLightStrip->getPixelColor(innerLightsIds[i]);
			// adjust
			uint32_t newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue, start, min, max);

			if(start != newColor)
			{
				// we changed at least 1 light
				changed = 1;
			}
			//save
			pLightStrip->setPixelColor(innerLightsIds[i], newColor);
		}

		return changed;
	}
