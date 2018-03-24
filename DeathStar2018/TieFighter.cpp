#include "TieFighter.h"

// Constructors/Destructors
//  

TieFighter::TieFighter (uint8_t newTargetNumber) {
	targetNumber = newTargetNumber;
	initAttributes();
}

TieFighter::~TieFighter () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void TieFighter::initAttributes ()
{

}






/**
 * to do: check for more than array size
 * @param  index zerobased index into arry of lights
 * @param  lightId zero based possition in NeoPixel  strip or circle
 */
void TieFighter::setLigntIdsOuter (uint8_t index, uint8_t lightId)
{
	outerLightIds[index] = lightId;
}


/**
 * to do: check for more than array size
 * @param  index zerobased index into arry of lights
 * @param  lightId zero based possition in NeoPixel  strip or circle
 */
void TieFighter::setLigntIdsInner (uint8_t index, uint8_t lightId)
{
	innerLightsIds[index] = lightId;
}


/**
 * this is call as part of main loop
 * Switch on script then call script run
 */
void TieFighter::run ()
{
}


/**
 * use switch to on Screen Class to update CurrentSceen pointer
 * then call sceen start
 */
void TieFighter::changeSceen (uint8_t newSceen)
{


	switch (newSceen)
	{
	case (int)Sceen::Off:
		sceen = newSceen;  // this is a sceen the actor can do
		nextUpdate =0;     // make it happen right away
		//currentSceen = offSceen;
		currentSceen->start();
		break;

	case (int)Sceen::TieFighterExplodes:
			sceen = newSceen;  // this is a sceen the actor can do
			nextUpdate =0;     // make it happen right away
			currentSceen = tieFighterExplode;
			currentSceen->start();
			break;

	};


}




