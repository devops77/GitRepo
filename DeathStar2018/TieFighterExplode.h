
#include <stdint.h>
#include "TieFighter.h"
#include "SceenBase.h"



#ifndef TIEFIGHTEREXPLODE_H
#define TIEFIGHTEREXPLODE_H

// order of steps
enum class TieFighterExplodeSteps { InitialFlash, FadeToRed, FadeToBlack, FinalState };

/**
  * class TieFighterExplode
  * 
  */

class TieFighterExplode : public SceenBase
{
private:
	// keeps track of what step we are on
	TieFighter* pFighter;
	TieFighterExplodeSteps nextStep;


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
  virtual void startSceen ();
  /**
   * think this will be a big switch based on step value
   */
  virtual void run ();




// steps to get this done
  void doInitialFlash();
  void doFadeToRed();
  void doFadeToBlack();


};

#endif // TIEFIGHTEREXPLODE_H
