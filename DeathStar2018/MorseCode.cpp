/*
 * MoreCode.cpp
 *
 *  Created on: Apr 11, 2018
 *      Author: BigDaddy
 */

#define DEBUG
#include "debugArduino.h"
#include "global.h"  //global defines
#include "MorseCode.h"

MorseCode::MorseCode() {
	// TODO Auto-generated constructor stub

}



MorseCode::~MorseCode() {
	// TODO Auto-generated destructor stub
}

void MorseCode::linkVentPort(VentPort* newPort)
{
	  pVentPort = newPort;
}
void MorseCode::linkDeathStarFace(DeathStarFace* newFace)
 {
	  pDeathStarFace = newFace;

 }

/**
 * init the vars when this script starts
 * set step = 0
 * updat = now
 */
void MorseCode::startSceen ()
{
	  DEBUG_PRINT("startSceen()");
	  nextUpdate=0; //MoresCodeSteps::PlayCode;
	  pVentPort->setAllLights(0x00);  // turn all lights off
	  pDeathStarFace->setAllLights(0x00); // turn all lights off
	  stepStartTime = millis();
	  nextStep = MoresCodeSteps::PlayCode;
	  mySeenIsDone = false;


}
/**
 * think this will be a big switch based on step value
 */
void MorseCode::run ()
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
		   case MoresCodeSteps::PlayCode: // get things started
			   dash(); dot(); dash(); dot(); letterPause(); //c
			   dot(); dash(); dot(); dot();  letterPause(); //l
			   dot(); dash();  letterPause(); //a
			   dot(); dash(); dot();  letterPause(); //r
			   dot();  letterPause(); //e
			   delay(1000);


			   nextStep = MoresCodeSteps::Flash;

			   break;
		   case MoresCodeSteps::Flash : // get things started
			   doFlash();

			   nextStep = MoresCodeSteps::FadeToBlack;
			   break;

		   case MoresCodeSteps::FadeToBlack : // get things started
			   doFadeToBlack();
			   break;


	   }
}

void MorseCode::dot()
{
	  pVentPort->setAllLights(0x00ff8080);  // turn all lights off
	  pDeathStarFace->setAllLights(0xff8080); // turn all lights off
	  delay(300);
	  pVentPort->setAllLights(0x00);  // turn all lights off
	  pDeathStarFace->setAllLights(0x00); // turn all lights off
	  delay(500);



}

void MorseCode::dash()
{
	  pVentPort->setAllLights(0x00ff8080);  // turn all lights off
	  pDeathStarFace->setAllLights(0xff8080); // turn all lights off
	  delay(700);
	  pVentPort->setAllLights(0x00);  // turn all lights off
	  pDeathStarFace->setAllLights(0x00); // turn all lights off
	  delay(500);


}
void MorseCode::wordPause()
{
	delay(1000);
}
void MorseCode::letterPause()
{
	delay(500);
}
void MorseCode::doFlash()
{
	pVentPort->setAllLights(0x0000ff);  // turn all lights off
	pDeathStarFace->setAllLights(0x0000ff); // turn all lights off
	nextUpdate = millis()+500;
	 nextStep = MoresCodeSteps::FadeToBlack;
}
void MorseCode::doFadeToBlack()
{

	change = pVentPort->fadeLights(-10,-20,-20, 0x00000000, 0x00FFFFFF);  // fade
	 	  pVentPort->updateLights();
	 	  change += pDeathStarFace->fadeLights(-12,-15,-20,0x00000000, 0x00FFFFFF);
	 	  pDeathStarFace->updateLights();
	 	  if(change > 0)
	 	  {
	 		  // more to change
	 		  nextUpdate = millis()+40;
	 		  nextStep = MoresCodeSteps::FadeToBlack;
	 	  }
	 	  else
	 	  {
	 		// done
	 		 mySeenIsDone = true;
	 	  }

}
