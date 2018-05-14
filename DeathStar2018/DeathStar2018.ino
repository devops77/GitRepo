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
#include "MorseCode.h"
#include "ModeSwitch.h"
#include "soundBoard.h"


#include "global.h"  //global defines

// global classes
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, NEOPIXEL_STRIP_PIN, NEO_RGB + NEO_KHZ800);
	Adafruit_NeoPixel deathStarFaceStrip = Adafruit_NeoPixel(FaceNumberOfLights, NEOPIXEL_DS_FACE_PIN, NEO_RGB + NEO_KHZ800);
	Adafruit_NeoPixel ring = Adafruit_NeoPixel(VentRingNumberOfLights, NEOPIXEL_RING_PIN, NEO_GRB + NEO_KHZ800);

	ModeSwitch modeSwitch = ModeSwitch();
	SoundBoard soundBoard =SoundBoard();

	int numberOfTargetsDown;

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

	MorseCode morseCode = MorseCode();
	SceenBase* pMorseCode;


	// vent port
	VentPort ventPort = VentPort();
	DeathStarFace deathStarFace = DeathStarFace();
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

	modeSwitch.setup();
	soundBoard.setup(&modeSwitch);


	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
	deathStarFaceStrip.begin();
	deathStarFaceStrip.show(); // Initialize all pixels to 'off'
	ring.begin();
	ring.show();


	tiefighter1.setUp(1, &strip, &soundBoard);
	tiefighter2.setUp(2, &strip, &soundBoard);
	tiefighter3.setUp(3, &strip, &soundBoard);
	tiefighter4.setUp(4, &strip, &soundBoard);
	tiefighter5.setUp(5, &strip, &soundBoard);

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
	deathStarFace.setUp(&deathStarFaceStrip, &soundBoard);

	deathStarExplode.linkVentPort(&ventPort);
	deathStarExplode.linkDeathStarFace(&deathStarFace);

	deathStarPlayGame.linkDeathStarFace(&deathStarFace);
	deathStarPlayGame.linkVentPort(&ventPort);

	morseCode.linkDeathStarFace(&deathStarFace);
	morseCode.linkVentPort(&ventPort);



	pTieFighter1Sceen = &tieFighter1PlaysGame;
	pTieFighter2Sceen = &tieFighter2PlaysGame;
	pTieFighter3Sceen = &tieFighter3PlaysGame;
	pTieFighter4Sceen = &tieFighter4PlaysGame;
	pTieFighter5Sceen = &tieFighter5PlaysGame;
	pDeathStarSceen = &deathStarExplode;
	pDeathStarSceen = &deathStarPlayGame;
	if(modeSwitch.getCurrentMode() == 6 )
	{
		pDeathStarSceen = &morseCode;
	}


	pTieFighter1Sceen->startSceen();
	pTieFighter2Sceen->startSceen();
	pTieFighter3Sceen->startSceen();
	pTieFighter4Sceen->startSceen();
	pTieFighter5Sceen->startSceen();
	pDeathStarSceen->startSceen();     //remove if we do not do morsecode

  	keepAlive=millis();


}

// The loop function is called in an endless loop
void loop()
{


	//delay(100);



//Add your repeated code here
//	DB_NAME_VALUE("before delay  ", 1);
//	DB_NAME_VALUE("Free Mem", freeMemory());
//	DB_NAME_VALUE("after delay  ", 2);
// check if revied first so as not to bounce

	soundBoard.update();   // see if we have to change state of sound pins

	if( !tiefighter1.getIsAlive() && tiefighter1.getTargetUp() )
	{
		DB_NAME_VALUE("Target up  ", 1);
		pTieFighter1Sceen = &tieFighter1PlaysGame;
		pTieFighter1Sceen->startSceen();
	}
	if( !tiefighter2.getIsAlive() && tiefighter2.getTargetUp() )
	{
		pTieFighter2Sceen = &tieFighter2PlaysGame;
		pTieFighter2Sceen->startSceen();
	}
	if( !tiefighter3.getIsAlive() && tiefighter3.getTargetUp() )
	{
		pTieFighter3Sceen = &tieFighter3PlaysGame;
		pTieFighter3Sceen->startSceen();
	}
	if( !tiefighter4.getIsAlive() && tiefighter4.getTargetUp() )
	{
		pTieFighter4Sceen = &tieFighter4PlaysGame;
		pTieFighter4Sceen->startSceen();
	}
	if( !tiefighter5.getIsAlive() && tiefighter5.getTargetUp() )
	{
		pTieFighter5Sceen = &tieFighter5PlaysGame;
		pTieFighter5Sceen->startSceen();
	}
/*

	if(!ventPort.getIsAlive() && !ventPort.isHit())
	{
		pDeathStarSceen = &deathStarPlayGame;
		pDeathStarSceen->startSceen();
	}

*/


//
// check if target down
//	DB_NAME_VALUE("about to check down  ", 4);
	//DB_NAME_VALUE("Free Mem", freeMemory());


	if( tiefighter1.getIsAlive() && !tiefighter1.getTargetUp() )
	{
		DB_NAME_VALUE("Target Down  ", 1);
//		DB_NAME_VALUE("Free Mem", freeMemory());
		pTieFighter1Sceen = &tieFighter1ExplodesSceen;
		pTieFighter1Sceen->startSceen();
	}

	if( tiefighter2.getIsAlive() && !tiefighter2.getTargetUp() )
	{
		DB_NAME_VALUE("Target Down  ", 2);
		pTieFighter2Sceen = &tieFighter2ExplodesSceen;
		pTieFighter2Sceen->startSceen();
	}
	if( tiefighter3.getIsAlive() && !tiefighter3.getTargetUp() )
	{
		DB_NAME_VALUE("Target Down  ", 3);
		pTieFighter3Sceen = &tieFighter3ExplodesSceen;
		pTieFighter3Sceen->startSceen();
	}
	if( tiefighter4.getIsAlive() && !tiefighter4.getTargetUp() )
	{
		DB_NAME_VALUE("Target Down  ", 4);
		pTieFighter4Sceen = &tieFighter4ExplodesSceen;
		pTieFighter4Sceen->startSceen();
	}

	if( tiefighter5.getIsAlive() && !tiefighter5.getTargetUp() )
	{
		DB_NAME_VALUE("Target Down  ", 5);
		pTieFighter5Sceen = &tieFighter5ExplodesSceen;
		pTieFighter5Sceen->startSceen();
	}

//	DB_NAME_VALUE("about to check vent  ", 8);


	if(ventPort.getIsAlive() && ventPort.isHit())
	{
		DB_NAME_VALUE("Vent Port Hit ", "True");
		pDeathStarSceen = &deathStarExplode;
		pDeathStarSceen->startSceen();
	}


	// now we need a count of number of tagets down
	numberOfTargetsDown = 0;
	if(!tiefighter1.getTargetUp()) numberOfTargetsDown++;
	if(!tiefighter2.getTargetUp()) numberOfTargetsDown++;
	if(!tiefighter3.getTargetUp()) numberOfTargetsDown++;
	if(!tiefighter4.getTargetUp()) numberOfTargetsDown++;
	if(!tiefighter5.getTargetUp()) numberOfTargetsDown++;



// do the seen updates


	pTieFighter1Sceen->run();
	pTieFighter2Sceen->run();
	pTieFighter3Sceen->run();
	pTieFighter4Sceen->run();
	pTieFighter5Sceen->run();
	pDeathStarSceen->run();

	if(pDeathStarSceen->sceenDone())
	{
		pDeathStarSceen = &deathStarPlayGame;
	}

// this code is to blink on board LED every second
		if(millis()-keepAlive > 1000)
		{
			// 1 second tick
			keepAlive=millis(); // set new hart beat
			if(onBoardLed == 0)
			{
				digitalWrite(LED_BUILTIN,HIGH);
				onBoardLed = 1;
				//DB_NAME_VALUE("keep alive HB", 1)
			}
			else
			{
				digitalWrite(LED_BUILTIN,LOW);
				onBoardLed = 0;
			}
		}
		




}
