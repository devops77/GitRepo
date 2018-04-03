#define DEBUG
#include "Arduino.h"
#include "debugArduino.h"
#include "global.h"  //global defines
#include "TieFighter.h"
#include "TieFighterPlaysGame.h"
#include "TieFighterExplode.h"
#include "VentPort.h"
#include "DeathStarPlayGame.h"
#include "DeathStarExplode.h"



#include "global.h"  //global defines

// global classes
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, NEOPIXEL_STRIP_PIN, NEO_RGB + NEO_KHZ800);
	Adafruit_NeoPixel ring = Adafruit_NeoPixel(VentRingNumberOfLights, NEOPIXEL_RING_PIN, NEO_GRB + NEO_KHZ800);

	// Tie Fighters
	TieFighter  tiefighter1 = TieFighter();
	TieFighter  tiefighter2 = TieFighter();
	TieFighter  tiefighter3 = TieFighter();
	TieFighter  tiefighter4 = TieFighter();
	TieFighter  tiefighter5 = TieFighter();

	TieFighterPlaysGame tieFighter1PlaysGame = TieFighterPlaysGame();
	TieFighterPlaysGame tieFighter2PlaysGame = TieFighterPlaysGame();
	TieFighterPlaysGame tieFighter3PlaysGame = TieFighterPlaysGame();
	TieFighterPlaysGame tieFighter4PlaysGame = TieFighterPlaysGame();
	TieFighterPlaysGame tieFighter5PlaysGame = TieFighterPlaysGame();

	TieFighterExplode tieFighter1ExplodesSceen = TieFighterExplode();
	TieFighterExplode tieFighter2ExplodesSceen = TieFighterExplode();
	TieFighterExplode tieFighter3ExplodesSceen = TieFighterExplode();
	TieFighterExplode tieFighter4ExplodesSceen = TieFighterExplode();
	TieFighterExplode tieFighter5ExplodesSceen = TieFighterExplode();

	SceenBase* pTieFighter1Sceen;
	SceenBase* pTieFighter2Sceen;
	SceenBase* pTieFighter3Sceen;
	SceenBase* pTieFighter4Sceen;
	SceenBase* pTieFighter5Sceen;
	SceenBase* pDeathStarSceen;


	// vent port
	VentPort ventPort = VentPort();
	DeathStarPlayGame deathStarPlayGame = DeathStarPlayGame();
	DeathStarExplode deathStarExplode = DeathStarExplode();


	uint8_t onBoardLed;
	unsigned long keepAlive;


//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);

	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
	ring.begin();
	ring.show();

	tiefighter1.setUp(1, &strip);
	tiefighter2.setUp(2, &strip);
	tiefighter3.setUp(3, &strip);
	tiefighter4.setUp(4, &strip);
	tiefighter5.setUp(5, &strip);

	tieFighter1ExplodesSceen.linkFighter(&tiefighter1);
	tieFighter2ExplodesSceen.linkFighter(&tiefighter2);
	tieFighter3ExplodesSceen.linkFighter(&tiefighter3);
	tieFighter4ExplodesSceen.linkFighter(&tiefighter4);
	tieFighter5ExplodesSceen.linkFighter(&tiefighter5);

	tieFighter1PlaysGame.linkFighter(&tiefighter1);
	tieFighter2PlaysGame.linkFighter(&tiefighter2);
	tieFighter3PlaysGame.linkFighter(&tiefighter3);
	tieFighter4PlaysGame.linkFighter(&tiefighter4);
	tieFighter5PlaysGame.linkFighter(&tiefighter5);



	ventPort.setUp(&ring);
	deathStarExplode.linkVentPort(&ventPort);
	deathStarPlayGame.linkVentPort(&ventPort);


	pTieFighter1Sceen = &tieFighter1PlaysGame;
	pTieFighter2Sceen = &tieFighter2PlaysGame;
	pTieFighter3Sceen = &tieFighter3PlaysGame;
	pTieFighter4Sceen = &tieFighter4PlaysGame;
	pTieFighter5Sceen = &tieFighter5PlaysGame;
	pDeathStarSceen = &deathStarPlayGame;

	pinMode(TIE_FIGHTER1_SHOOT_PIN, OUTPUT);
	pinMode(TIE_FIGHTER2_SHOOT_PIN, OUTPUT);
	pinMode(TIE_FIGHTER3_SHOOT_PIN, OUTPUT);
	pinMode(TIE_FIGHTER4_SHOOT_PIN, OUTPUT);
	pinMode(TIE_FIGHTER5_SHOOT_PIN, OUTPUT);



	pTieFighter1Sceen->startSceen();
	pTieFighter2Sceen->startSceen();
	pTieFighter3Sceen->startSceen();
	pTieFighter4Sceen->startSceen();
	pTieFighter5Sceen->startSceen();
	pDeathStarSceen->startSceen();

  	keepAlive=millis();


}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here



// TODO look for events

// do the seen updates


// TODO only 1 sceen
	pTieFighter1Sceen->run();
//	pTieFighter2Sceen->run();
//	pTieFighter3Sceen->run();
//	pTieFighter4Sceen->run();
//	pTieFighter5Sceen->run();
	pDeathStarSceen->run();





	delay(100);
		if(millis()-keepAlive > 60000000)
		{
			// if we are here it has been a while since we got a hart beet
			 DEBUG_PRINT("KeepAlive fired");
			 //DB_NAME_VALUE("keepAlive value",keepAlive);

			keepAlive=millis(); // set new hart beat
			// done with sceen
			if(onBoardLed == 0)
			{
				digitalWrite(LED_BUILTIN,HIGH);
				onBoardLed = 1;
				pTieFighter2Sceen = &tieFighter2ExplodesSceen;
				pTieFighter2Sceen->startSceen();

			}
			else
			{
				digitalWrite(LED_BUILTIN,LOW);
				onBoardLed = 0;
				pTieFighter1Sceen = &tieFighter1ExplodesSceen;
				pTieFighter1Sceen->startSceen();
			}
		}
		




}
