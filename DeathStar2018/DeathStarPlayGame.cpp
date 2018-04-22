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
	  nextStep =DeathStarPlayGameSteps::PlayGame;
	  pVentPort->setAllLights(0x00);  // turn all lights off
	  pDeathStarFace->setAllLights(0x00); // turn all lights off
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
		   case DeathStarPlayGameSteps::PlayGame: // get things started
			   doChase();
			   doTwinkle();
			   break;
		   case DeathStarPlayGameSteps::FinalState : // get things started

			   break;

	   }
}

#define TwinkleTime 1000 // mil secs between starts of twinlkel
#define FadeTime     50

void DeathStarPlayGame::doChase()
{
	
	//DB_NAME_VALUE("doChase", nextUpdate);
	
	// THE VENT HAS THE CHASES EFFECT
	pVentPort->fadeLights(-25,-20,-25, 0x000007000,0x00ffffff);
	pVentPort->shiftLights(0x00d0d0d0);
	pVentPort->updateLights();
	nextUpdate = millis()+50;

}

void DeathStarPlayGame::doTwinkle()
{


	//DB_NAME_VALUE("doTwinkle", nextUpdate);
	bool faceNeedsUdate=false;
	// the face has a sparkel effect
	if(millis()> nextFaceFadeTime)
	{
		pDeathStarFace->fadeLights(-1,-1,-1, 0x0000000,0x00ffffff);    //fade all
		nextFaceFadeTime = millis()+FadeTime;
		faceNeedsUdate|=true;
	}
	if(millis()>nextTwinkleTime)
	{
		uint32_t randColor = NeoPixelColor::joinColor(random(0,40),random(0,40), random(10,60) );
		pDeathStarFace->setRandomLight(0,200,randColor);
		nextTwinkleTime = millis() + TwinkleTime;
		faceNeedsUdate|=true;
	}
		
	if(faceNeedsUdate)
	{
		pDeathStarFace->updateLights();
	}
	
	

}

