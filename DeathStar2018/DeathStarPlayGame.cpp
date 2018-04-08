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
	  nextUpdate =0;
	  nextStep =DeathStarPlayGameSteps::PlayGame;
	  nextUpdate=0; //start right away
	  pVentPort->setAllLights(0x00FFFFFF);  // update the vent port
	  pDeathStarFace->setAllLights(0x00FFFF80);
	  DEBUG_PRINT("DeathStarPlayGame::startSceen()");

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
			   break;
		   case DeathStarPlayGameSteps::FinalState : // get things started

			   break;

	   }
}


void DeathStarPlayGame::doChase()
{
	//DB_NAME_VALUE("doChase", nextUpdate);
	pVentPort->fadeLights(-25,-20,-25, 0x000007000,0x00ffffff);
	pVentPort->shiftLights(0x00d0d0d0);
	pVentPort->updateLights();

	nextUpdate = millis()+50;

}

