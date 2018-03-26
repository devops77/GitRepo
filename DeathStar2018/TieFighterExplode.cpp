#include "TieFighterExplode.h"

// Constructors/Destructors
//  

TieFighterExplode::TieFighterExplode () {
initAttributes();
}

TieFighterExplode::~TieFighterExplode ()
{

	step = 0;

}

void TieFighterExplode::linkFighter(TieFighter* newFighter)
{
	pFighter = newFighter;
}


void TieFighterExplode::initAttributes ()
{

}

/**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
   void TieFighterExplode::start ()
  {
  }


  /**
   * think this will be a big switch based on step value
   */
   void TieFighterExplode::run ()
  {
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
   * all off
   */
   setp1()
  {
	 // all off
  }

   /**
    * Inner white flash
    */
   step2()
   {


   }

   /**
    * fade to red
    */
   step3()
   {

   }





/*
 * switch (newSceen)
	{
	case (int)Sceen::Off:
		sceen = newSceen;  // this is a sceen the actor can do
		nextUpdate =0;     // make it happen right away
		//currentSceen = offSceen;
		currentSceen->start();
		break;

	case (int)Sceen::TieFighterExplodes:
			sceen = newSceen;  // this is a sceen the actor can do
			nextUpdate =0;     // make it happen right away
			currentSceen = pTieFighterExplodes;
			currentSceen->start();
			break;
	};
 */
