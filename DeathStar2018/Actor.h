
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

protected:
	uint32_t nextUpdate;



public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Actor ();

  /**
   * Empty Destructor
   */
  virtual ~Actor ();



  /**
   * will cause the actor to change seen and do other stuff
   * todo:
   *    * force all lights off
   *    * set seen value
   *    *
   * 
   */
  virtual  void changeSceen () = 0;





  void setNextUpdate (uint32_t new_var);

  /**
   * Get the value of nextUpdate
   * @return the value of nextUpdate
   */
  uint32_t getNextUpdate ();



};

#endif // ACTOR_H
