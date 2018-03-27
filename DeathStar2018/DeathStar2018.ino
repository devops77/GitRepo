#include "Arduino.h"
#include "debugArduino.h"
#include "global.h"  //global defines
#include "TieFighter.h"
#include "TieFighterExplode.h"



#include "global.h"  //global defines

// global classes
	#define PIN 8
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);


	TieFighter  tiefighter1 = TieFighter(1, &strip);
	TieFighterExplode tieFighterExplodesSceen = TieFighterExplode();



//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);

	tieFighterExplodesSceen.linkFighter(&tiefighter1);
	tieFighterExplodesSceen.startSceen();


 	strip.begin();
  	strip.show(); // Initialize all pixels to 'off'
/*
	TieFighter*  pTiefighter1 = new TieFighter(1, &strip);
	TieFighterExplode*  pTieFighterExplodesSceen = new TieFighterExplode();  //link seen to actor
	pTieFighterExplodesSceen->linkFighter(pTiefighter1);
	pTieFighterExplodesSceen->startSceen()
*/



}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here



// TODO look for events

// do the seen updates

delay(2000);
// TODO only 1 sceen

		tieFighterExplodesSceen.run();
		if(tieFighterExplodesSceen.getNextUpdate() > 6000)
		{
			// done with sceen
			delay(6000);
			tieFighterExplodesSceen.startSceen();
		}
		




}
