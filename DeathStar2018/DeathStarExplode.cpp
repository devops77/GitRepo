#define DEBUG
#include "debugArduino.h"
#include "global.h"  //global defines
#include "DeathStarExplode.h"





	 /**
	   * Empty Constructor
	   */
DeathStarExplode::DeathStarExplode ()
{
	  nextUpdate =0;
	  nextStep =DeathStarExplodeSteps::StartExplode;
}

DeathStarExplode::~DeathStarExplode()
{
}



  void DeathStarExplode::linkVentPort(VentPort* newPort)
  {
	  pVentPort = newPort;
  }


  /**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
  void DeathStarExplode::startSceen ()
  {
	  nextUpdate =0;
	  nextStep =DeathStarExplodeSteps::StartExplode;
	  nextUpdate=0; //start right away
	  DEBUG_PRINT("DeathStarExplode::startSceen()");

  }
  /**
   * think this will be a big switch based on step value
   */
  void DeathStarExplode::run ()
  {
	   //DB_NAME_VALUE("Run with nextupdate=",nextUpdate);
	   // this is the hart of making this sceen happen
	   if(nextUpdate>millis())
	   {
		   return;  // nothing to do at this time
	   }

	   //  DEBUG_PRINT("TieFighterExplode::run()");
	   // if we get here there is work to do
	   switch(nextStep)
	   {
		   case DeathStarExplodeSteps::StartExplode: // get things started
			   doStartExplode();
			   break;
		   case DeathStarExplodeSteps::FinalState : // get things started
			   //doFlash();
			   break;

	   }
  }




// steps to get this done
  void DeathStarExplode::doStartExplode()
  {

  }

  void DeathStarExplode::doRingThrob()
  {

  }


  void DeathStarExplode::doDeathStarSpread()
  {

  }

  void DeathStarExplode::doFlash()
  {

  }

  void DeathStarExplode::doFadeToBlack()
  {

  }

