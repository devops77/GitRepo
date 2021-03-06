/*
 * DeathStarPlayGame.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: BigDaddy
 */

#define DEBUG
#include "debugArduino.h"
#include "global.h"  //global defines
#include "DeathStarPlayGame.h"

DeathStarPlayGame::DeathStarPlayGame() {
	// TODO Auto-generated constructor stub

}

DeathStarPlayGame::~DeathStarPlayGame() {
	// TODO Auto-generated destructor stub
}

void DeathStarPlayGame::linkVentPort(VentPort* newPort)
{
	  pVentPort = newPort;
}
void DeathStarPlayGame::linkDeathStarFace(DeathStarFace* newFace)
 {
	  pDeathStarFace = newFace;

 }

/**
 * init the vars when this script starts
 * set step = 0
 * updat = now
 */
void DeathStarPlayGame::startSceen ()
{
	  DEBUG_PRINT("DeathStarPlayGame::startSceen()");
	  nextUpdate=0; //start right away


	  nextStep =DeathStarPlayGameSteps::FadeToBlack;
	  pVentPort->setAllLights(0x0000f0);  // turn all lights blue
	  pDeathStarFace->setAllLights(0x0000ff); // turn all lights blue
	  stepStartTime = millis();
	  nextFaceFadeTime = stepStartTime;
	  nextTwinkleTime =  stepStartTime;

}
/**
 * think this will be a big switch based on step value
 */
void DeathStarPlayGame::run ()
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
	   	   case DeathStarPlayGameSteps::FadeToBlack:
	   		   doFadeToBlack();
	   		   break;
	   	   case DeathStarPlayGameSteps::PlayGame: // get things started
			   doChase();
			   doTwinkle();
			   break;
		   case DeathStarPlayGameSteps::FinalState : // get things started

			   break;

	   }
}

#define TwinkleTime 280 // mil secs between starts of twinlkel
#define FadeTime     50

void DeathStarPlayGame::doChase()
{
	
	//DB_NAME_VALUE("doChase", nextUpdate);
	
	// THE VENT HAS THE CHASES EFFECT
	pVentPort->fadeLights(-10,-07,-10, 0x00000800,0x00f0f0f0);
	pVentPort->shiftLights(0x00202020);
	pVentPort->updateLights();
	nextUpdate = millis()+50-(numberOfTargetsDown*7);

}




void DeathStarPlayGame::doTwinkle()
{

	// try to make
	int fadeRate = -1 -(2*numberOfTargetsDown); // orig value of -1
	int newColorMax = 30 + (5*numberOfTargetsDown); //orgi value of 30



	//DB_NAME_VALUE("doTwinkle", nextUpdate);
	bool faceNeedsUdate=false;

	// the face has a sparkel effect
	if(millis()> nextFaceFadeTime)
	{
		pDeathStarFace->fadeLights(fadeRate,fadeRate,fadeRate, 0x0000000,0x00ffffff);    //fade all
		nextFaceFadeTime = millis()+25+FadeTime;
		faceNeedsUdate|=true;
	}
	if(millis()>nextTwinkleTime)
	{
		int numberOfRandomLights =0;
		switch(numberOfTargetsDown)
		{
			case 0:
				numberOfRandomLights = 2;
				break;

			case 1:
				numberOfRandomLights = 4;
				break;

			case 2:
				numberOfRandomLights = 8;
				break;

			case 3:
				numberOfRandomLights = 12;
				break;

			case 4:
				numberOfRandomLights = 20;
				break;

			case 5:
				numberOfRandomLights = 30;
				break;

			case 6:
				numberOfRandomLights = 45;
				break;
			default:
				numberOfRandomLights = 10;

		}

		for( int i=0; i<numberOfRandomLights; i++)
		{
			uint32_t randColor = NeoPixelColor::joinColor(random(0,newColorMax),random(0,newColorMax), random(10,newColorMax+20) );
			pDeathStarFace->setRandomLight(0,200,randColor);

		}

		uint32_t randColor = NeoPixelColor::joinColor(random(20,0xff),random(20,0xff), random(10,0xff) );
		pDeathStarFace->setLight(4, randColor); // this is the neopixel in the vent port


		nextTwinkleTime = millis() + TwinkleTime;
		faceNeedsUdate|=true;
	}
		
	if(faceNeedsUdate)
	{
		pDeathStarFace->updateLights();
	}
	
	

}


void DeathStarPlayGame::doFadeToBlack()
{

	int change = pVentPort->fadeLights(-15,-15,-15, 0x00000000, 0x00FFFFFF);  // fade
	pVentPort->updateLights();
	change += pDeathStarFace->fadeLights(-15,-15,-15,0x00000000, 0x00FFFFFF);
	pDeathStarFace->updateLights();
	if(change > 0)
	{
	  // more to change
	  nextUpdate = millis()+40;
	}
	else
	{
	// done
	  nextStep = DeathStarPlayGameSteps::PlayGame;
	}

}
