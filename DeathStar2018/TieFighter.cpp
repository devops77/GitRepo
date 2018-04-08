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
/*
	DEBUG_PRINT("Post init inner light ids");
	DB_NAME_VALUE(0, innerLightsIds[0]);
	DB_NAME_VALUE(1, innerLightsIds[1]);


	 DEBUG_PRINT("post init outerLightids");
		DB_NAME_VALUE(0, outerLightIds[0]);
		DB_NAME_VALUE(1, outerLightIds[1]);
		DB_NAME_VALUE(2, outerLightIds[2]);
		DB_NAME_VALUE(3, outerLightIds[3]);
		DB_NAME_VALUE(4, outerLightIds[4]);
		DB_NAME_VALUE(5, outerLightIds[5]);
*/
}


bool TieFighter::getTargetUp()
{
//DB_NAME_VALUE("get traget ", myHitSwitchPin);
//DB_NAME_VALUE("Free Mem", freeMemory());
	if(digitalRead(myHitSwitchPin))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool TieFighter::getIsAlive()
{
	//DB_NAME_VALUE("Check Alive :", myIsAlive)
	//DB_NAME_VALUE("Free Mem", freeMemory());
	return myIsAlive;
}
void TieFighter::setIsAlive(bool newValue)
{
	myIsAlive = newValue;
}



void TieFighter::initAttributes ()
{
	// set up my lights
	switch (targetNumber)
	{
		case 1:
			// set Laser outp pin
			myLaserPin = TIE_FIGHTER1_SHOOT_PIN;
			myHitSwitchPin = TIE_FIGHTER1_HIT_PIN;
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
			// set Laser outp pin
			myLaserPin = TIE_FIGHTER2_SHOOT_PIN;
			myHitSwitchPin = TIE_FIGHTER2_HIT_PIN;
			//set inner lights
			this->setLightIdsInner(0,13);
			this->setLightIdsInner(1,14);
			// set outer lights
			this->setLightIdsOuter(0,10);
			this->setLightIdsOuter(1,11);
			this->setLightIdsOuter(2,12);
			this->setLightIdsOuter(3,15);
			this->setLightIdsOuter(4,16);
			this->setLightIdsOuter(5,17);
			break;

		case 3:
			// set Laser outp pin
			myLaserPin = TIE_FIGHTER3_SHOOT_PIN;
			myHitSwitchPin = TIE_FIGHTER3_HIT_PIN;
			//set inner lights
			this->setLightIdsInner(0,23);
			this->setLightIdsInner(1,24);
			// set outer lights
			this->setLightIdsOuter(0,20);
			this->setLightIdsOuter(1,21);
			this->setLightIdsOuter(2,22);
			this->setLightIdsOuter(3,25);
			this->setLightIdsOuter(4,26);
			this->setLightIdsOuter(5,27);
			break;
		case 4:
			// set Laser outp pin
			myLaserPin = TIE_FIGHTER4_SHOOT_PIN;
			myHitSwitchPin = TIE_FIGHTER4_HIT_PIN;
			//set inner lights
			this->setLightIdsInner(0,33);
			this->setLightIdsInner(1,34);
			// set outer lights
			this->setLightIdsOuter(0,30);
			this->setLightIdsOuter(1,31);
			this->setLightIdsOuter(2,32);
			this->setLightIdsOuter(3,35);
			this->setLightIdsOuter(4,36);
			this->setLightIdsOuter(5,37);
			break;
		case 5:
			// set Laser outp pin
			myLaserPin = TIE_FIGHTER5_SHOOT_PIN;
			myHitSwitchPin = TIE_FIGHTER5_HIT_PIN;
		//set inner lights
			this->setLightIdsInner(0,43);
			this->setLightIdsInner(1,44);
			// set outer lights
			this->setLightIdsOuter(0,40);
			this->setLightIdsOuter(1,41);
			this->setLightIdsOuter(2,42);
			this->setLightIdsOuter(3,45);
			this->setLightIdsOuter(4,46);
			this->setLightIdsOuter(5,47);
			break;

		}
	pinMode(myLaserPin, OUTPUT);
	pinMode(myHitSwitchPin,INPUT_PULLUP);


	  // DB_NAME_VALUE("Write pin: ",myLaserPin );

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
		DB_NAME_VALUE("For Target Number", targetNumber);

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
void TieFighter::startPlayLaserSound()
{
	digitalWrite(TIE_FIGHTER_SHOOT_SOUND,LOW);   // must be low for 150 ms
}


/*
 * end trigger (not sound)
 */
void TieFighter::endPlayLaserSound()
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


void TieFighter::setLaserBrightness(uint8_t brightness)
{
	analogWrite(myLaserPin,brightness);
/*	if(myLaserPin ==7)
	{
   DB_NAME_VALUE("Write pin: ",myLaserPin );
   DB_NAME_VALUE("Brightness: ", brightness);
	}
	*/
}



uint8_t TieFighter::getTargetNumber()
{
	return targetNumber;
}




