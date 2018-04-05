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
	  nextStep =DeathStarExplodeSteps::Throb;
}

DeathStarExplode::~DeathStarExplode()
{
}



  void DeathStarExplode::linkVentPort(VentPort* newPort, DeathStarFace* newFace)
  {
	  pVentPort = newPort;
	  pDeathStarFace = newFace;
  }


  /**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
  void DeathStarExplode::startSceen ()
  {
	  stepStartTime =0;
	  lightOnCount =0;
	  nextStep =DeathStarExplodeSteps::RingThrob;
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
	   	   case DeathStarExplodeSteps::RingThrob: // get things started
			   doRingThrob();
			   break;
	   	   case DeathStarExplodeSteps::Throb: // get things started
	   		   doThrob();
			   break;
	   	   case DeathStarExplodeSteps::Flash1: // get things started
			   doFlash1();
			   break;
		   case DeathStarExplodeSteps::Flash2: // get things started
			   doFlash2();
			   break;

		   case DeathStarExplodeSteps::FadeToBlack : // get things started
			   doFadeToBlack();
			   break;

	   }
  }


  /*
   *  generates a throb value basd on time, update, and grain
   */
  uint32_t DeathStarExplode::getThrobValue(unsigned long updateInterval, unsigned long grain)
  {

	  unsigned long x = millis()/updateInterval;
	  x %= grain;
	  float xf = x; // convert to float
	  float grainf= grain;
	  xf = sin(xf*PI/(grainf));
	  xf*=255.0;
	  int z= xf;
	  return z;

  }


  void DeathStarExplode::doRingThrob()
  {
	  uint32_t color = getThrobValue(50,50);
	  color <<=16; // move to red
	  pVentPort->setAllLights(color);
	  nextUpdate = millis()+50;
//	  DB_NAME_VALUE("stepStartTime    ", stepStartTime);
	  if(stepStartTime + 2000 < millis())
	  {
		  // next step
		  stepStartTime = millis();
		  lightOnCount=0;
		  nextStep =DeathStarExplodeSteps::Throb;
		  DEBUG_PRINT("ring Throb change state");
	  }
  }

 /**
  * throb both ring and all other lights
  */
  void DeathStarExplode::doThrob()
  {
	  //DEBUG_PRINT("All Throb");
	  uint32_t color = getThrobValue(50,50);
	  color <<=16; // move to red


	  pVentPort->setAllLights(color);  // update the vent port

	  // for the death star face we do the string 1 light at a time
	  lightOnCount++;
	  for(int i=0; i<lightOnCount; i++)
	  {
		  pDeathStarFace->setLight(i, color);
	  }
	  pDeathStarFace->updateLights();
	  if(lightOnCount >= 50)
		  lightOnCount = 49;


	  nextUpdate = millis()+50;



  }


  void DeathStarExplode::doFlash1()
  {
	  DEBUG_PRINT("Flash1");
  }


  void DeathStarExplode::doFlash2()
  {
	  DEBUG_PRINT("Flash2");

  }

  void DeathStarExplode::doFadeToBlack()
  {
	  DEBUG_PRINT("Fade To Black");

  }

