#define DEBUG
#include "Arduino.h"
#include "debugArduino.h"
#include "global.h"  //global defines
#include "TieFighter.h"
#include "TieFighterExplode.h"
#include "VentPort.h"
#include "DeathStarExplode.h"



#include "global.h"  //global defines

// global classes
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, NEOPIXEL_STRIP_PIN, NEO_RGB + NEO_KHZ800);
	Adafruit_NeoPixel ring = Adafruit_NeoPixel(VentRingNumberOfLights, NEOPIXEL_RING_PIN, NEO_GRB + NEO_KHZ800);


	TieFighter  tiefighter1 = TieFighter();
	TieFighterExplode tieFighter1ExplodesSceen = TieFighterExplode();

	VentPort ventPort = VentPort();
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
	tieFighter1ExplodesSceen.linkFighter(&tiefighter1);
	tieFighter1ExplodesSceen.startSceen();

	ventPort.setUp(&ring);
	deathStarExplode.linkVentPort(&ventPort);
	deathStarExplode.startSceen();





  	keepAlive=millis();

}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here



// TODO look for events

// do the seen updates


// TODO only 1 sceen
	tieFighter1ExplodesSceen.run();
	deathStarExplode.run();

	//	tieFighterExplodesSceen.run();
	delay(50);
		if(millis()-keepAlive > 6000)
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

			}
			else
			{
				digitalWrite(LED_BUILTIN,LOW);
				onBoardLed = 0;
			}
			tieFighter1ExplodesSceen.startSceen();
			//deathStarExplode.startSceen();
		}
		




}
