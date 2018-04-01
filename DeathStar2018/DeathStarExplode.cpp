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
	  nextStep =DeathStarExplodeSteps::PlayGame;
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
	  nextStep =DeathStarExplodeSteps::PlayGame;
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
		   case DeathStarExplodeSteps::PlayGame: // get things started
			   doChase();
			   break;
		   case DeathStarExplodeSteps::Explode : // get things started
			   doFlash();
			   break;

	   }
  }


void DeathStarExplode::doChase()
{
	//DB_NAME_VALUE("doChase", nextUpdate);
	pVentPort->fadeLights(-25,-20,-25, 0x000007000,0x00ffffff);
	pVentPort->shiftLights(0x00d0d0d0);
	pVentPort->updateLights();

	nextUpdate = millis()+3;

}

// steps to get this done
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

