#include "Arduino.h"
#include "debugArduino.h"
#include "TieFighter.h"
#include "TieFighterExplode.h"



//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);

	TieFighter*  pTiefighter1 = new TieFighter(1);
	TieFighterExplode*  pTieFighterExplodesSceen = new TieFighterExplode();  //link seen to actor
	pTieFighterExplodesSceen->linkFighter(pTiefighter1);




}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here


// TODO look for events

// do the seen updates


// TODO only 1 sceen

	  // put your main code here, to run repeatedly:
	  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	  DEBUG_PRINT("High");
	  delay(2000);                       // wait for a second

	  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	  DEBUG_PRINT("Low");
	  delay(2000);


}
