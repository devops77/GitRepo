
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "NeoPixelColor.h"
#include <stdint.h>




#ifndef ACTOR_H
#define ACTOR_H



/**
  * class Actor
  * 
  */

class Actor
{

private:
	void initAttributes () ;


public:


  /**
   * Empty Constructor
   */
  Actor ();

  /**
   * Empty Destructor
   */
  virtual ~Actor ();



};

#endif // ACTOR_H
