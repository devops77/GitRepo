#define DEBUG
/*
 * TieFighterPlaysGame.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: BigDaddy
 */

#include "global.h"
#include "TieFighterPlaysGame.h"
#include "debugArduino.h"
#include "TieFighter.h"

TieFighterPlaysGame::TieFighterPlaysGame() {
	// TODO Auto-generated constructor stub

}

TieFighterPlaysGame::~TieFighterPlaysGame() {
	// TODO Auto-generated destructor stub
}

void TieFighterPlaysGame::linkFighter(TieFighter* newFighter)
{
	pFighter = newFighter;
	DEBUG_PRINT("TieFighterPlaysGame::Linked ");

}



/**
   * init the vars when this script starts
   * set step = 0
   * updatE = now
   */
   void TieFighterPlaysGame::startSceen ()
  {
	   DEBUG_PRINT("TieFighterPlaysGame::startSceen()");
	   nextStep =TieFighterPlayGameSteps::WaitToShoot;
	   nextUpdate=0; //start right away
	   pFighter->setIsAlive(true);

  }


  /**
   * will decide when and what to do
   * think this will be a big switch based on step value
   */
   void TieFighterPlaysGame::run ()
  {
		//DEBUG_PRINT("TieFighterPlaysGame::RUN()");
	   //DB_NAME_VALUE("Run with nextupdate=",nextUpdate);
	   // this is the hart of making this sceen happen
	   if(nextUpdate>millis())
	   {
		   return;  // nothing to do at this time
	   }


	   // if we get here there is work to do
	   switch(nextStep)
	   {
	   	   case TieFighterPlayGameSteps::WaitToShoot: // get things started
	   		doWaitToShootStep();
	   		   break;
	   	   case TieFighterPlayGameSteps::StartLazer : // get things started
	   		doStartLazerStep();
	   		   break;
	   	   case TieFighterPlayGameSteps::FadeLazer : // get things started
	   		doFadeLaserStep();
	   		   break;
	   	   case TieFighterPlayGameSteps::ShotDown :
	   		   doShotDownStep();
	   		   break;

	   }

  }

   void TieFighterPlaysGame::doWaitToShootStep()
   {

	   //Improved 2 var method  tried 200  and 1 to 10
	   unsigned long gap = 400; // this is the gap you want to have between fire events
	   unsigned long spread = gap*5; // spread is the duration of time to spread ot fire events
	   unsigned long delta =  random(1,6); // get the rand part of spread
	   delta *= spread;
	   delta += gap*(pFighter->getTargetNumber()-1);



	   nextUpdate = millis()+ delta;
	   nextStep =TieFighterPlayGameSteps::StartLazer;
   }
   void TieFighterPlaysGame::doStartLazerStep()
   {
	  // DB_NAME_VALUE("laser fire for taget:", pFighter->getTargetNumber());

	   pFighter->startPlayLaserSound();   // start the trigger  needs to be down for 150ms so start as soon as possiable
	   nextUpdate = millis()+1000; //duration of brigth blast
	   // turn laser on
	   laserBrightness = 0xff;
	   pFighter->setLaserBrightness(laserBrightness); // full brightness
	   nextStep =TieFighterPlayGameSteps::FadeLazer;

   }


   void TieFighterPlaysGame::doFadeLaserStep()
   {
#define LASER_FADE_RATE 30
	   pFighter->endPlayLaserSound();   // start the trigger  needs to be down for 150ms so start as soon as possiable
	   nextUpdate = millis()+40; //some time to do other things
	   //laserBrightness >>= 1 ; // devide
	   laserBrightness -= LASER_FADE_RATE;

	   //DB_NAME_VALUE("Do fade brightness: ", laserBrightness );

	   pFighter->setLaserBrightness(laserBrightness); // full brightness
	   if(laserBrightness <= (LASER_FADE_RATE+10))
	   {
		   laserBrightness = 0;
		   pFighter->setLaserBrightness(laserBrightness); // full brightness
		   nextStep =TieFighterPlayGameSteps::WaitToShoot;
	   }
   }

   void TieFighterPlaysGame::doShotDownStep()
   {
	  nextUpdate = millis()+END_OF_TIME;  // loop for ever, no more updates
	  return;
   }


