#define DEBUG

#include "Sceens.h"
#include "TieFighter.h"
#include "global.h"
#include "debugArduino.h"

// Constructors/Destructors
//  

TieFighter::TieFighter(){};  // must give the target number


TieFighter::~TieFighter () { }

void TieFighter::setUp(uint8_t newTargetNumber, Adafruit_NeoPixel* newStrip)
{
	targetNumber = newTargetNumber;
	pLightStrip = newStrip;

	initAttributes();

	DEBUG_PRINT("Post init inner light ids");
	DB_NAME_VALUE_HEX(0, innerLightsIds[0]);
	DB_NAME_VALUE_HEX(1, innerLightsIds[1]);


	 DEBUG_PRINT("post init outerLight"
			 "ids");
		DB_NAME_VALUE_HEX(0, outerLightIds[0]);
		DB_NAME_VALUE_HEX(1, outerLightIds[1]);
		DB_NAME_VALUE_HEX(2, outerLightIds[2]);
		DB_NAME_VALUE_HEX(3, outerLightIds[3]);
		DB_NAME_VALUE_HEX(4, outerLightIds[4]);
		DB_NAME_VALUE_HEX(5, outerLightIds[5]);

}

void TieFighter::initAttributes ()
{
	// set up my lights
	switch (targetNumber)
	{
		case 1:
			//set inner lights
			this->setLightIdsInner(0,3);
			this->setLightIdsInner(1,4);
			// set outer lights
			this->setLightIdsOuter(0,0);
			this->setLightIdsOuter(1,1);
			this->setLightIdsOuter(2,2);
			this->setLightIdsOuter(3,5);
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

	DEBUG_PRINT("innerLights set");
	DB_NAME_VALUE_HEX(0, innerLightsIds[0]);
	DB_NAME_VALUE_HEX(1, innerLightsIds[1]);


	 DEBUG_PRINT("outerLights set");
		DB_NAME_VALUE_HEX(0, outerLightIds[0]);
		DB_NAME_VALUE_HEX(1, outerLightIds[1]);
		DB_NAME_VALUE_HEX(2, outerLightIds[2]);
		DB_NAME_VALUE_HEX(3, outerLightIds[3]);
		DB_NAME_VALUE_HEX(4, outerLightIds[4]);
		DB_NAME_VALUE_HEX(5, outerLightIds[5]);


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

/*
	DB_NAME_VALUE("setLightIdsOuter index", index);
		DB_NAME_VALUE_HEX(0, outerLightIds[0]);
		DB_NAME_VALUE_HEX(1, outerLightIds[1]);
		DB_NAME_VALUE_HEX(2, outerLightIds[2]);
		DB_NAME_VALUE_HEX(3, outerLightIds[3]);
		DB_NAME_VALUE_HEX(4, outerLightIds[4]);
		DB_NAME_VALUE_HEX(5, outerLightIds[5]);
*/
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
 * start play  sound shoot sound
 */
void TieFighter::startPlayShootSound()
{
	digitalWrite(TIE_FIGHTER_SHOOT_SOUND,LOW);   // must be low for 150 ms
}


/*
 * end trigger (not sound)
 */
void TieFighter::endPlayShootSound()
{
	digitalWrite(TIE_FIGHTER_SHOOT_SOUND,LOW);   // must be low for 150 ms
}

/**
 * start play  sound shoot sound
 */
void TieFighter::startPlayExplodeSound()
{
	digitalWrite(TIE_FIGHTER_EXPLODE_PIN,HIGH);   // must be low for 150 ms
}


/*
 * end trigger (not sound)
 */
void TieFighter::endPlayExplodeSound()
{
	digitalWrite(TIE_FIGHTER_EXPLODE_PIN,HIGH);   // must be low for 150 ms
}


/**
 * set inner lights to newvalue will not show at this time
 */
void TieFighter::setLigntInnerNoShow(uint32_t newColor)
{

	for( int i=0; i<TieFighterNumberOfLightsInner; i++ )
	{
		pLightStrip->setPixelColor(innerLightsIds[i], newColor);
		/*
		DB_NAME_VALUE("TieFighter::setLigntInnerNoShow() light ID",innerLightsIds[i]);
		DB_NAME_VALUE_HEX("setValue",newColor);
		*/
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
		/*
		DEBUG_PRINT("TieFighter::setLigntOuterNoShow()");
		DB_NAME_VALUE("TieFighter::setLigntOuterNoShow() i", i);
		DB_NAME_VALUE("TieFighter::setLigntOuterNoShow() light ID", outerLightIds[i]);
		DB_NAME_VALUE_HEX("setValue",newColor);
		*/

	}

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

/**
 * fade outer lights to newvalue will not show at this time
 */
uint8_t TieFighter::fadeLightOuterNoShow(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
{
	uint8_t changed = 0; // assume nothing changed

	for( int i=0; i<TieFighterNumberOfLightsOuter; i++ )
	{
		// get
		uint32_t start = pLightStrip->getPixelColor(outerLightIds[i]);
		// adjust

		uint32_t newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue,start, min, max);
		if(start != newColor)
		{
			// we changed at least 1 light
			changed = 1;
		}

		//save
		pLightStrip->setPixelColor(outerLightIds[i], newColor);
	}

	return changed;
}







