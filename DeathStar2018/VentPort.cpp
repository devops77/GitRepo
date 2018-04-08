#define DEBUG

#include "global.h"
#include "debugArduino.h"
#include "Sceens.h"

#include "VentPort.h"

// Constructors/Destructors
//  

VentPort::VentPort () {
}

VentPort::~VentPort () {
}
//  
// Methods
//  

void VentPort::setUp(Adafruit_NeoPixel* newRing)
{
	//DEBUG_PRINT("VentPort::setUp");
	pLightRing = newRing;
	ringHead=0;
	isAlive=true;
	pinMode( VENT_TARGET_HIT, INPUT_PULLUP);


}
  /**
   * update the Neopixels to show new settings
   */
  void VentPort::updateLights()
  {
	  //DB_NAME_VALUE("VentPort::updateLights", "about to call update");
	  pLightRing->show();

  }
  /**
   * start play  sound explode sound
   */
  void VentPort::startPlayExplodeSound()
  {
	  digitalWrite(DEATH_STAR_EXPLODE_PIN,LOW);   // must be low for 150 ms
  }

/*
   * end trigger (not sound)
   */
  void VentPort::endPlayExplodeSound()
  {
	  digitalWrite(DEATH_STAR_EXPLODE_PIN,HIGH);   // must be low for 150 ms
  }



  /**
  ** will cause next light in ring to go bright
  **/
  void VentPort::shiftLights(uint32_t setColor)
  {
	  // just turn set the light for the next light
	  // range check
	  ringHead++;   // move head by one
	  if( ringHead >= VentRingNumberOfLights)
	  {
		  // wrap around
		  ringHead = 0;
	  }
	  //set
	//  DB_NAME_VALUE("set one light head", ringHead);
	//  DB_NAME_VALUE_HEX("set one light heacolord", setColor);
	  pLightRing->setPixelColor(ringHead, setColor);


  }

  /**
  ** will cause all lights to fade
  **/
  int VentPort::fadeLights(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max)
  {

	  uint32_t start =0;
	  uint32_t newColor=0;

	for( int i=0; i<VentRingNumberOfLights; i++ )
	{
		// get
		 start = pLightRing->getPixelColor(i);
		// adjust
		 newColor = NeoPixelColor::shiftColor(deltaRed, deltaGreen, deltaBlue, start, min, max);

		//save
		pLightRing->setPixelColor(i, newColor);
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
  void VentPort::setAllLights(uint32_t color)
  {

		for( int i=0; i<VentRingNumberOfLights; i++ )
		{
			pLightRing->setPixelColor(i, color);
		}
		pLightRing->show();
  }


/**
** will check if the target is hit
** as of this writing I thing we will use a 74LS74 to latch the event
**/
bool VentPort::isHit()
{
	
		if(digitalRead(VENT_TARGET_HIT))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool VentPort::getIsAlive()
{
		return isAlive;
}
void VentPort::setIsAlive(bool newValue)
{
	isAlive = newValue;
}
