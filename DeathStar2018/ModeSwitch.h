

#ifndef MODESWITCH_H
#define MODESWITCH_H
class ModeSwitch
{
	// reads mose switch and give a number  0 to 5
	private:
		const unsigned char myBasePin = 14;  // pin for lowest bit of switch port
		int currentMode = 0;
		void readSwitch();
	public:
		void setup();   // called to get current mode switch state state
		int getCurrentModeNow();
		int getCurrentMode();
		
	

};

#endif  //MODESWITCH
