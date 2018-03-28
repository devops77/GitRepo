
#include "debugArduino.h"
#include "NeoPixelColor.h"

// Constructors/Destructors
//  

NeoPixelColor::NeoPixelColor () {
}

NeoPixelColor::~NeoPixelColor() {
}

void NeoPixelColor::splitColor(uint32_t input, int & red, int & green, int & blue )
{

	blue = input & 0x000000ff;
	input = input >> 8;
	green = input & input & 0x000000ff;
	input = input >> 8;
	red = input & 0x000000ff;


}

uint8_t NeoPixelColor::shiftOneColor(int start, int delta, int min, int max)
{
	int newValue = start+ delta;

	if(newValue < min) newValue = min;
	if(newValue > max) newValue = max;

	return(uint8_t)newValue;
}



uint32_t NeoPixelColor::shiftColor(int redDelta, int greenDelta, int blueDelta, uint32_t start, uint32_t min, uint32_t max)
{

	int redStart, greenStart, blueStart;
	int redMin, greenMin, blueMin;
	int redMax, greenMax, blueMax;
	int redFinal, greenFinal, blueFinal;

/*
	DEBUG_PRINT(" shiftColor ");
	DEBUG_PRINT2(start,HEX);
	DEBUG_PRINT2(min,HEX);
	DEBUG_PRINT2(max,HEX);
*/
	splitColor(start, redStart, greenStart, blueStart);
	splitColor(min, redMin, greenMin, blueMin);
	splitColor(max, redMax, greenMax, blueMax);


	redFinal = shiftOneColor(redStart, redDelta, redMin, redMax);


	greenFinal = shiftOneColor(greenStart, greenDelta, greenMin, greenMax);
	blueFinal = shiftOneColor(blueStart, blueDelta, blueMin, blueMax);

	uint32_t final = Adafruit_NeoPixel::Color(redFinal, greenFinal, blueFinal);
//	DEBUG_PRINT2(final,HEX);
	return  final;

}


