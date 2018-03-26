#include "Arduino.h"
#include "debugArduino.h"
#include "TieFighter.h"
#include "TieFighterExplode.h"


//global defines
#define TieFighterExplodesPin 3
#define END_OF_TIME 86400000    // 86400000 is one day 


// global classes
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);




//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);

 	strip.begin();
  	strip.show(); // Initialize all pixels to 'off'

	TieFighter*  pTiefighter1 = new TieFighter(1, &strip);
	TieFighterExplode*  pTieFighterExplodesSceen = new TieFighterExplode();  //link seen to actor
	pTieFighterExplodesSceen->linkFighter(pTiefighter1);
	pTieFighterExplodesSceen->startSceen()




}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here


// TODO look for events

// do the seen updates


// TODO only 1 sceen
		pTieFighterExplodesSceen->run();
		
		if(pTieFighterExplodesSceen->getNextUpdate() > 60000)
		{
			// done with sceen
			delay(6000)
			pTieFighterExplodesSceen->startSceen()
		}
		


	  // put your main code here, to run repeatedly:
	  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	  DEBUG_PRINT("High");
	  delay(2000);                       // wait for a second

	  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	  DEBUG_PRINT("Low");
	  delay(2000);


}
