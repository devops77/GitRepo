#include "Actor.h"


#ifndef VENTPORT_H
#define VENTPORT_H

#define VentRingNumberOfLights 30

/**
  * class VentPort
  * 
  */

class VentPort :  public Actor
{

private:
	Adafruit_NeoPixel* pLightRing;
	uint8_t ringHead;


public:


  /**
   * Empty Constructor
   */
  VentPort ();

  /**
   * Empty Destructor
   */
  virtual ~VentPort ();

	/**
	** set things up 
	*/
	void setUp(Adafruit_NeoPixel* newRing);
	
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
  ** will cause nex light in ring to go bright
  **/
  void shiftLights();
  
  /**
  ** will cause all lights to fade
  **/
  void fadeLights(int deltaRed, int deltaGreen, int deltaBlue, uint32_t min, uint32_t max);
  


};   // end of class struct

#endif // VENTPORT_H
