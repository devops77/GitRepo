#include <stdint.h>
#include "VentPort.h"
#include "DeathStarFace.h"
#include "SceenBase.h"


#ifndef DEATHSTAREXPLODE_H
#define DEATHSTAREXPLODE_H

// order of steps
enum class DeathStarExplodeSteps { RingThrob, Throb,TrobFade, Flash1, FastBlack, Flash2, FadeToBlack, FinalState };

/**
  * class DeathStarExplode
  *
  */

class DeathStarExplode : public SceenBase
{
private:
	// keeps track of what step we are on
	VentPort* pVentPort;
	DeathStarFace* pDeathStarFace;
	DeathStarExplodeSteps nextStep;
	uint8_t lightOnCount;
	unsigned long stepStartTime;




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
  void linkDeathStarFace(DeathStarFace* newFace);


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


  void doStartExplode();

// steps to get this done
  void doRingThrob();
  void doThrob();
  void doTrobFade();
  void doFlash1();
  void doFastBlack();
  void doFlash2();
  void doFadeToBlack();

  uint32_t getThrobValue(unsigned long updateInterval, unsigned long grain);
  uint32_t getThrobValue2(float maxLevel, float waveLength, float offset, float scale);



};

#endif // DEATHSTAREXPLODE_H
