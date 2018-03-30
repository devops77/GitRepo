#include <stdint.h>
#include "VentPort.h"
#include "SceenBase.h"



#ifndef DEATHSTAREXPLODE_H
#define DEATHSTAREXPLODE_H

// order of steps
enum class DeathStarExplodeSteps { PlayGame, Explode, FinalState };

/**
  * class DeathStarExplode
  *
  */

class DeathStarExplode : public SceenBase
{
private:
	// keeps track of what step we are on
	VentPort* pVentPort;
	DeathStarExplodeSteps nextStep;



public:

	 /**
	   * Empty Constructor
	   */

	 DeathStarExplode ();




  /**
   * Empty Destructor
   */
  virtual ~DeathStarExplode ();


  void linkVentPort(VentPort* newPort);


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
  void doRingThrob();
  void doDeathStarSpread();
  void doFlash();
  void doFadeToBlack();


};

#endif // DEATHSTAREXPLODE_H
