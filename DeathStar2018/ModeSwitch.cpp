/*
* MoseSwitch CPP
* used to read the mode switch settings
* values 0 to 5 are valid
* 
*/
#define DEBUG
#include "Arduino.h"
#include "global.h"  //global defines

#include "ModeSwitch.h"


/*****
** read and calc mode value
**/
void ModeSwitch::readSwitch()
{
	int pinValue;
	for(uint8_t i=0; i<6; i++)
	{
		pinValue=digitalRead(myBasePin+i);
		if(pinValue==0)
		{
			currentMode = i;
		}
	}
	
}

/**
** set up pins
**/
void ModeSwitch::setup()
{
	for(unsigned char i=0; i<6; i++)
	{
		pinMode(myBasePin+i, INPUT_PULLUP);
	}
	readSwitch();   // not sure if this will work but worth a try	
}



int ModeSwitch::getCurrentModeNow()
{
	// for now I will get the current value but may need to change so it get the value just before restart press
	readSwitch();
	return currentMode;
}

int ModeSwitch::getCurrentMode()
{
	
	return currentMode;

}
