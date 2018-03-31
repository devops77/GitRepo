/*
 * TieFighterPlaysGame.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: BigDaddy
 */

#include "global.h"
#include "TieFighterPlaysGame.h"

TieFighterPlaysGame::TieFighterPlaysGame() {
	// TODO Auto-generated constructor stub

}

TieFighterPlaysGame::~TieFighterPlaysGame() {
	// TODO Auto-generated destructor stub
}

void TieFighterPlaysGame::linkFighter(TieFighter* newFighter)
{
	pFighter = newFighter;
}



/**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
   void TieFighterPlaysGame::startSceen ()
  {
	   nextStep =TieFighterPlayGameSteps::WaitToShoot;
	   nextUpdate=0; //start right away
	  // DEBUG_PRINT("TieFighterPlaysGame::startSceen()");


  }


  /**
   * will decide when and what to do
   * think this will be a big switch based on step value
   */
   void TieFighterPlaysGame::run ()
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
	   // set up for next fire with 2 random range think that 5 guys are fireing at the start and only 1 at end
	   nextUpdate = millis()+random(3000,9000);
	   nextStep =TieFighterPlayGameSteps::StartLazer;
   }
   void TieFighterPlaysGame::doStartLazerStep()
   {
	   pFighter->startPlayLaserSound();   // start the trigger  needs to be down for 150ms so start as soon as possiable
	   nextUpdate = millis()+800; //duration of brigth blast
	   // turn laser on
	   laserBrightness = 0xff;
	   pFighter->setLaserBrightness(laserBrightness); // full brightness
	   nextStep =TieFighterPlayGameSteps::FadeLazer;

   }


   void TieFighterPlaysGame::doFadeLaserStep()
   {
	   pFighter->endPlayLaserSound();   // start the trigger  needs to be down for 150ms so start as soon as possiable
	   nextUpdate = millis()+20; //some time to do other things
	   laserBrightness >>= 2; // divie by 2
	   pFighter->setLaserBrightness(laserBrightness); // full brightness
	   if(laserBrightness==0)
	   {
		   nextStep =TieFighterPlayGameSteps::WaitToShoot;
	   }
   }

   void TieFighterPlaysGame::doShotDownStep()
   {
	  nextUpdate = millis()+END_OF_TIME;  // loop for ever, no more updates
	  return;
   }


