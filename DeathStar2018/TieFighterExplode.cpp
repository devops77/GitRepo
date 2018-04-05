#define DEBUG
#include "debugArduino.h"
#include "global.h"  //global defines
#include "TieFighterExplode.h"


void TieFighterExplode::initAttributes ()
{
	nextStep = TieFighterExplodeSteps::InitialFlash;
	nextUpdate = 0;
}

// Constructors/Destructors
//  

TieFighterExplode::TieFighterExplode () {
initAttributes();
}

TieFighterExplode::~TieFighterExplode ()
{
}

void TieFighterExplode::linkFighter(TieFighter* newFighter)
{
	pFighter = newFighter;
}



/**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
   void TieFighterExplode::startSceen ()
  {
	   nextStep =TieFighterExplodeSteps::InitialFlash;
	   nextUpdate=0; //start right away
	  DEBUG_PRINT("TieFighterExplode::startSceen()");
	   pFighter->startPlayExplodeSound();   // start the trigger  needs to be down for 150ms so start as soon as possiable
	   pFighter->setIsAlive(false);
	   pFighter->setLaserBrightness(0);
  }


  /**
   * will decide when and what to do
   * think this will be a big switch based on step value
   */
   void TieFighterExplode::run ()
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
	   	   case TieFighterExplodeSteps::InitialFlash: // get things started
	   		   doInitialFlash();
	   		   break;
	   	   case TieFighterExplodeSteps::FadeToRed : // get things started
	   		   doFadeToRed();
	   		   break;
	   	   case TieFighterExplodeSteps::FadeToBlack : // get things started
	   		   doFadeToBlack();
	   		   break;
	   }

  }






  /**
   * gen bright white in center with slight red on outer
   */
  void TieFighterExplode::doInitialFlash()
  {

	  //DEBUG_PRINT("TieFighterExplode::doInitialFlash()");

	  // turn lights on
	  pFighter->setLigntInnerNoShow(0x00FFFFFF);
	  pFighter->setLigntOuterNoShow(0x00FFF0F0);
	  pFighter->updateLights();

	  // set up next step
	  nextStep = TieFighterExplodeSteps::FadeToBlack;
	  nextUpdate = millis()+300;



  }


  /**
   * fade to red
   * outer fades to lower red and faster
   *
   * 	Not used
   */
  void TieFighterExplode::doFadeToRed()
  {

	//  DEBUG_PRINT("TieFighterExplode::doFadeToRed()");
	//  DB_NAME_VALUE("stepIterationCount", stepIterationCount);
	  uint8_t change = 0;


	 // DEBUG_PRINT("TieFighterExplode::doFadeToRed()  do work");
	  //if we got here there is work to do
	  change += pFighter->fadeLightInnerNoShow(-20,-26, -26,  0x00000000, 0x00ffffff);   /// delta min, max
	  change += pFighter->fadeLightOuterNoShow(-30,-30, -30, 0x00000000, 0x00ffffff);   /// delta min, max
	  pFighter->updateLights();
	  pFighter->endPlayExplodeSound();   // end the trigger of sound
	  nextUpdate = millis()+5;
	  stepIterationCount--;

	  if(change ==0)
	  {   // no lights changed so we are done with this step
		  // move on to next step
		  // set up next step
		  nextStep = TieFighterExplodeSteps::FadeToBlack;
		  nextUpdate = millis()+5;
		  return;
	  }


  }


  void TieFighterExplode::doFadeToBlack()
  {
	 // DEBUG_PRINT("TieFighterExplode::doFadeToBlack()  do work");

	  uint8_t change = 0;

	  //if we got here there is work to do
	  change += pFighter->fadeLightInnerNoShow(-20,-26, -26,  0x00000000, 0x00ffffff);   /// delta min, max
	  change += pFighter->fadeLightOuterNoShow(-30,-30, -30, 0x00000000, 0x00ffffff);   /// delta min, max
	  pFighter->updateLights();
	  nextUpdate = millis()+5;

	  if(change ==0)
	  {   // no lights changed so we are done with this step
		  // move on to next step
		  // set up next step
		  //DEBUG_PRINT("TieFighterExplode:: sceen is done");
		  nextUpdate = millis()+END_OF_TIME;  // loop for ever, no more updates
		  return;
	  }


  }


