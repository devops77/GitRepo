#include "debugArduino.h"
#include "Sceens.h"
#include "TieFighter.h"


// Constructors/Destructors
//  

TieFighter::TieFighter ()
{

}

TieFighter::~TieFighter () { }

/**
  * setup call from ino file
  */
 void TieFighter::setUp(int newTargetNumber, Adafruit_NeoPixel* newStrip)
 {
	 targetNumber = newTargetNumber;
	 pLightStrip = newStrip;
	 initAttributes ();

 }

void TieFighter::initAttributes ()
{


	// set up my lights
	switch (targetNumber)
	{
		case 1:
			//set inner lights
			setLightIdsInner(0,4);
			this->setLightIdsInner(1,5);
			// set outer lights
			this->setLightIdsOuter(0,0);
			this->setLightIdsOuter(1,1);
			this->setLightIdsOuter(2,2);
			this->setLightIdsOuter(3,3);
			this->setLightIdsOuter(4,6);
			this->setLightIdsOuter(5,7);
			break;

		case 2:
			//set inner lights
			this->setLightIdsInner(0,24);
			this->setLightIdsInner(1,25);
			// set outer lights
			this->setLightIdsOuter(0,20);
			this->setLightIdsOuter(1,21);
			this->setLightIdsOuter(2,22);
			this->setLightIdsOuter(3,23);
			this->setLightIdsOuter(4,26);
			this->setLightIdsOuter(5,27);
			break;

		case 3:
			break;
		case 4:
			break;
		case 5:
			break;

		}

	/* debug code
	 *
	 */

}



/**
 * to do: check for more than array size
 * @param  index zerobased index into arry of lights
 * @param  lightId zero based possition in NeoPixel  strip or circle
 */
void TieFighter::setLightIdsOuter (uint8_t index, uint8_t lightId)
{
	outerLightIds[index] = lightId;
}


/**
 * to do: check for more than array size
 * @param  index zerobased index into arry of lights
 * @param  lightId zero based possition in NeoPixel  strip or circle
 */
void TieFighter::setLightIdsInner (uint8_t index, uint8_t lightId)
{

	innerLightsIds[index] = lightId;
}


/**
 * update the Neopixels to show new settings
 */
void TieFighter::updateLights()
{
	pLightStrip->show();
}

/**
 * pla a sound
 */
void TieFighter::playSound(int pinNumber)
{
	// TODO : play sound
}

/**
 * set inner lights to newvalue will not show at this time
 */
void TieFighter::setLigntInnerNoShow(uint32_t newColor)
{

	for( int i=0; i<TieFighterNumberOfLightsInner; i++ )
	{
		pLightStrip->setPixelColor(innerLightsIds[i], newColor);

	}
}


/**
 * set outer lights to newvalue will not show at this time
 */
void TieFighter::setLigntOuterNoShow(uint32_t newColor)
{
	for( int i=0; i<TieFighterNumberOfLightsOuter; i++ )
	{
		pLightStrip->setPixelColor(outerLightIds[i], newColor);

	}

}

/**
 * fade inner lights to newvalue will not show at this time
 */
void TieFighter::fadeLightInnerNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
{
	/*
	DEBUG_PRINT("Red Delta");
	DEBUG_PRINT2(deltaRed, HEX);
	DEBUG_PRINT("Green Delta");
	DEBUG_PRINT2(deltaGreen,HEX);
	DEBUG_PRINT("Blue Delta");
	DEBUG_PRINT2(deltaBlue,HEX);
	*/
	/*
	DEBUG_PRINT("min");
		DEBUG_PRINT2(min, HEX);
		DEBUG_PRINT("max");
		DEBUG_PRINT2(max,HEX);
    */

	for( int i=0; i<TieFighterNumberOfLightsInner; i++ )
	{
		// get
		uint32_t start = pLightStrip->getPixelColor(innerLightsIds[i]);
		DEBUG_PRINT2(start, HEX);
		// adjust
		DEBUG_PRINT(" adjust color call shift");
		uint32_t newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue, start, min, max);
		DEBUG_PRINT2(newColor, HEX);
		//save
		pLightStrip->setPixelColor(innerLightsIds[i], newColor);
	}



}

/**
 * fade outer lights to newvalue will not show at this time
 */
void TieFighter::fadeLightOuterNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
{
	for( int i=0; i<TieFighterNumberOfLightsOuter; i++ )
	{
		// get
		uint32_t start = pLightStrip->getPixelColor(outerLightIds[i]);
		// adjust

		uint32_t newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue,start, min, max);

		//save
		pLightStrip->setPixelColor(outerLightIds[i], newColor);
	}

}







