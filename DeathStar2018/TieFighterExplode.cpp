#include "debugArduino.h"
#include "TieFighterExplode.h"

void TieFighterExplode::initAttributes ()
{
	nextStep = 0;
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
	   nextStep =0;
	   DEBUG_PRINT("TieFighterExplode::startSceen()");

  }


  /**
   * will decide when and what to do
   * think this will be a big switch based on step value
   */
   void TieFighterExplode::run ()
  {
	   // this is the hart of making this sceen happen
	   if(nextUpdate>millis())
	   {
		   return;  // nothing to do at this time
	   }

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
   * Set the value of step
   * keeps track of what step we are on
   * @param new_var the new value of step
   */
   void TieFighterExplode::setStep (uint8_t new_var)   {
      step = new_var;
  }

  /**
   * Get the value of step
   * keeps track of what step we are on
   * @return the value of step
   */
  uint8_t TieFighterExplode::getStep ()   {
    return step;
  }

  /**
   * gen bright white in center with slight red on outer
   */
  void TieFighterExplode::doInitialFlash()
  {

	  DEBUG_PRINT("TieFighterExplode::doInitialFlash()");

	  // turn lights on
	  pFighter->setLigntInnerNoShow(0x00FFFFFF);
	  pFighter->setLigntOuterNoShow(0x00FFF0F0);
	  pFighter->updateLights();

	  // TODO : play sound
	  pFighter->playSound(TieFighterExplodesPin);

	  // set up next step
	  nextStep = TieFighterExplodeSteps::FadeToRed;
	  stepIterationCount = 100;
	  nextUpdate = millis()+300;



  }


  /**
   * fade to red
   * outer fades to lower red and faster
   */
  void TieFighterExplode::doFadeToRed()
  {
	  if(stepIterationCount <= 0)
	  {
		  // move on to next step
		  // set up next step
		  nextStep = TieFighterExplodeSteps::FadeToBlack;
		  stepIterationCount = 100;
		  nextUpdate = millis()+20;
		  return;
  	  }
	  DEBUG_PRINT("TieFighterExplode::doFadeToRed()");
	  //if we got here there is work to do
	  pFighter->fadeLightInnerNoShow(-20,-20, -20,  0x00ff0000, 0x00ffffff);   /// delta min, max
	  pFighter->fadeLightOuterNoShow(-60,-60, -60, 0x00800000, 0x00ffffff);   /// delta min, max
	  nextUpdate = millis()+80;
  }


  void TieFighterExplode::doFadeToBlack()
  {
	  if(stepIterationCount <= 0)
	  {
		  DEBUG_PRINT("TieFighterExplode:: sceen is done");
		  nextUpdate = millis()+END_OF_TIME;  // loop for ever, no more updates
		  return;
  	  }
	  DEBUG_PRINT("TieFighterExplode::doFadeToBlack()");
	  //if we got here there is work to do
	  pFighter->fadeLightInnerNoShow(-20,-20, -20, 0x00000000, 0x00ffffff);   /// delta min, max
	  pFighter->fadeLightOuterNoShow(-30,-30, -30, 0x00000000, 0x00ffffff);   /// delta min, max
	  nextUpdate = millis()+80;
  }




