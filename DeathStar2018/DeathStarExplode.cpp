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



  void DeathStarExplode::linkVentPort(VentPort* newPort)

  {
	  pVentPort = newPort;
  }

  void DeathStarExplode::linkDeathStarFace(DeathStarFace* newFace)
  {
	  pDeathStarFace = newFace;

  }

  /**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
  void DeathStarExplode::startSceen ()
  {
	  DEBUG_PRINT("DeathStarExplode::startSceen()");

	  stepStartTime = millis();
	  pVentPort->setIsAlive(false);
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
	   	   case DeathStarExplodeSteps::RingThrob:
			   doRingThrob();
			   break;
	   	   case DeathStarExplodeSteps::Throb:
	   		   doThrob();
			   break;
	   	   case DeathStarExplodeSteps::TrobFade:
	   			doTrobFade();
	   			break;
	   	   case DeathStarExplodeSteps::Flash1:
			   doFlash1();
			   break;
	   	   case DeathStarExplodeSteps::FastBlack:
			   doFastBlack();
			   break;
		   case DeathStarExplodeSteps::Flash2:
			   doFlash2();
			   break;

		   case DeathStarExplodeSteps::FadeToBlack :
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
	  xf*=128.0;
	  int z= xf;
	  return z;

  }
  
  
	uint32_t DeathStarExplode::getThrobValue2(float maxLevel, float waveLength, float offset, float scale)
	{
		unsigned long time = millis() - stepStartTime; // get a time based number starting with near zero
		float radTime = time; // convert to float
		float brightness = sin(PI*radTime/waveLength*2);
		brightness +=1; // nedd all positive 
		brightness *=maxLevel;
		brightness = brightness * scale + offset;
		int y =brightness; // convert to integer to drop decimals
		return y;
		
		
		
	}
  
#define MaxThrob 80.0
#define WaveLength 1000.0   // throb2 pulse duration
#define ThrobOffset 40.0
#define ThrobScale 0.8

  void DeathStarExplode::doRingThrob()
  {
	 // DB_NAME_VALUE("DoRingThrob", 1);
//	  uint32_t color = getThrobValue(50,50);
	  uint32_t color = getThrobValue2(MaxThrob, WaveLength, ThrobOffset, ThrobScale);
	  //DB_NAME_VALUE("Throb value",color);
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
//	  uint32_t color = getThrobValue(50,50);
	uint32_t color = getThrobValue2(MaxThrob, WaveLength, ThrobOffset, ThrobScale);

	  color <<=16; // move to red


	  pVentPort->setAllLights(color);  // update the vent port

	  // for the death star face we do the string 1 light at a time
	  lightOnCount = (millis()- stepStartTime)/100;

	  //lightOnCount++;
	  for(int i=0; i<lightOnCount; i++)
	  {
		  pDeathStarFace->setLight(i, color);
	  }
	  pDeathStarFace->updateLights();
	  if(lightOnCount >= FaceNumberOfLights)
		  lightOnCount = FaceNumberOfLights-1;

	  nextUpdate = millis()+50;
	  if(stepStartTime + 10000 < millis())
	  {  // move on
		  nextStep = DeathStarExplodeSteps::TrobFade;

	  }



  }


  void DeathStarExplode::doFlash1()
  {
	  DEBUG_PRINT("Flash1");
	  pVentPort->setAllLights(0x00FFFFFF);  // update the vent port
	  pDeathStarFace->setAllLights(0x00FFFF80);
	  nextUpdate = millis()+30;
	  nextStep = DeathStarExplodeSteps::FastBlack;
  }

  void DeathStarExplode::doFastBlack()
  {
	  DEBUG_PRINT("Fast Black");
	  DEBUG_PRINT("Flash1");
	  pVentPort->setAllLights(0x00000000);  // update the vent port
	  pDeathStarFace->setAllLights(0x00000000);
	  nextUpdate = millis()+400;
	  nextStep = DeathStarExplodeSteps::Flash2;
  }
  

  void DeathStarExplode::doFlash2()
  {
	  DEBUG_PRINT("Flash2");
	  pDeathStarFace->startPlayExplodeSound();
	  pVentPort->setAllLights(0x00FFFFFF);  // update the vent port
	  pDeathStarFace->setAllLights(0x00FFFF80);
	  nextUpdate = millis()+700;
	  nextStep = DeathStarExplodeSteps::FadeToBlack;

  }

  void DeathStarExplode::doTrobFade()
  {
	  //DEBUG_PRINT("Trob Fade Fade ");
	  uint8_t change;

	  change = pVentPort->fadeLights(-5,-15,-15, 0x00200000, 0x00FFFFFF);  // fade to red
	  pVentPort->updateLights();
	  change += pDeathStarFace->fadeLights(-5,-15,-15,0x00080000, 0x00FFFFFF);
	  pDeathStarFace->updateLights();
	  nextUpdate = millis()+50;


	  if(change ==0)
	  {
		  nextUpdate = millis()+300;
		  nextStep = DeathStarExplodeSteps::Flash1;
	  }
  }

  void DeathStarExplode::doFadeToBlack()
   {
 	 // DEBUG_PRINT("Fade To Black");
 	  uint8_t change;

 	  change = pVentPort->fadeLights(-10,-20,-20, 0x00000000, 0x00FFFFFF);  // fade to red
 	  pVentPort->updateLights();
 	  change += pDeathStarFace->fadeLights(-12,-15,-20,0x00000000, 0x00FFFFFF);
 	  pDeathStarFace->updateLights();
 	  if(change > 0)
 	  {
 		  // more to change
 		  nextUpdate = millis()+40;
 		  nextStep = DeathStarExplodeSteps::FadeToBlack;
 	  }
 	  else
 	  {
 		// done
 		nextUpdate = END_OF_TIME;
 	  }

   }

