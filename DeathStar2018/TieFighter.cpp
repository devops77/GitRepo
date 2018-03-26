#include "Sceens.h"
#include "TieFighter.h"


// Constructors/Destructors
//  

TieFighter::TieFighter (uint8_t newTargetNumber) {
	targetNumber = newTargetNumber;
	initAttributes();
}

TieFighter::~TieFighter () { }


void TieFighter::initAttributes ()
{
	// set up my lights
	switch (targetNumber)
	{
		case 0:
			this->setLigntIdsInner(0, 4);
			this->setLigntIdsInner(0, 5);
			this->setLigntIdsOuter(0,0);
			this->setLigntIdsOuter(0,1);
			this->setLigntIdsOuter(0,2);
			this->setLigntIdsOuter(0,3);
			this->setLigntIdsOuter(0,6);
			this->setLigntIdsOuter(0,7);
			this->setLigntIdsOuter(0,8);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;

		}



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
 * use switch to on Screen Class to update CurrentSceen pointer
 * then call sceen start
 */
void TieFighter::changeSceen ()
{

// TODO  Turn off all lights??? maybe??




}



