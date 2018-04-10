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
  int DeathStarFace::fadeLights(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
   {

 	  uint32_t start =0;
 	  uint32_t newColor=0;


	for( int i=0; i<FaceNumberOfLights; i++ )
	{
		// get
		 start = pLightStrip->getPixelColor(i);
		// adjust
		 newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue, start, min, max);

		//save
		pLightStrip->setPixelColor(i, newColor);
	}

	if(start == newColor)
	{
		return 0;
	}
	else
	{
		return 1;
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
  
    void DeathStarFace::setRandomLight(uint8_t minId, uint8_t maxId, uint32_t color)
  {
//	  DB_NAME_VALUE("set i ", i);
//	  DB_NAME_VALUE("set C ", color);
	if(maxId>=FaceNumberOfLights)
	{
		maxId = FaceNumberOfLights-1;
	}
	  pLightStrip->setPixelColor(random(minId, maxId), color);
  }


