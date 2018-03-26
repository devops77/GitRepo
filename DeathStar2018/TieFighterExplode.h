

#include <stdint.h>
#include "TieFighter.h"
#include "SceenBase.h"



#ifndef TIEFIGHTEREXPLODE_H
#define TIEFIGHTEREXPLODE_H

/**
  * class TieFighterExplode
  * 
  */

class TieFighterExplode : public SceenBase
{
private:
	// keeps track of what step we are on
	uint8_t step;
	TieFighter* pFighter;


	  void initAttributes () ;



public:

	 /**
	   * Empty Constructor
	   */

	 TieFighterExplode ();




  /**
   * Empty Destructor
   */
  virtual ~TieFighterExplode ();


  void linkFighter(TieFighter* newFighter);


  /**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
  virtual void start ();
  /**
   * think this will be a big switch based on step value
   */
  virtual void run ();


  /**
   * Set the value of step
   * keeps track of what step we are on
   * @param new_var the new value of step
   */
  virtual void setStep (uint8_t new_var);

  /**
   * Get the value of step
   * keeps track of what step we are on
   * @return the value of step
   */
  virtual uint8_t getStep ()  ;




  void setp1();
  void setp2();
  void setp3();
  void setp4();

};

#endif // TIEFIGHTEREXPLODE_H
