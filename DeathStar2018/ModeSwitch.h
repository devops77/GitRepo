

#ifndef MODESWITCH_H
#define MODESWITCH_H

//enum class ModeSwitchValues {Debug, Levels100_80_80, Level100_80_60, Level100_80_50, Level100_60_60, Clare};



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
