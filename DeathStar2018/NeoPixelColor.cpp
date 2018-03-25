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
	input = input >> 4;
	green = input & input & 0x000000ff;
	input = input >> 4;
	red = input & 0x000000ff;
}

uint8_t NeoPixelColor::shiftOneColor(int start, int delta, int min, int max)
{
	int newValue = start+ delta;

	if(newValue < min) newValue = min;
	if(newValue > max) newValue = max;

	return(uint8_t)newValue;
}

uint32_t NeoPixelColor::shiftColor(int32_t start, uint32_t delta, uint32_t min, uint32_t max)
{

	int redStart, greenStart, blueStart;
	int redDelta, greenDelta, blueDelta;
	int redMin, greenMin, blueMin;
	int redMax, greenMax, blueMax;
	int redFinal, greenFinal, blueFinal;

	splitColor(start, redStart, greenStart, blueStart);
	splitColor(delta, redDelta, greenDelta, blueDelta);
	splitColor(min, redMin, greenMin, blueMin);
	splitColor(max, redMax, greenMax, blueMax);

	redFinal = shiftOneColor(redStart, redDelta, redMin, redMax);
	greenFinal = shiftOneColor(greenStart, greenDelta, greenMin, greenMax);
	blueFinal = shiftOneColor(blueStart, blueDelta, blueMin, blueMax);



	return Adafruit_NeoPixel::Color(redFinal, greenFinal, blueFinal);

}


