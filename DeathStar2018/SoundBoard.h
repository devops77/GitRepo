#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include "ModeSwitch.h"

class SoundBoard
{
	// Controls Sound board sounds
	private:
		const int myBasePin = 6;  // pin for lowest trigger
		const unsigned long triggerDownTime = 130; // time in ms that trigger must be down  (min is 125)
		const int deathStarExplodeAudioPin = 0;
		const int tieFighterExplode80AudioPin = 1;
		const int tieFighterExplode60AudioPin = 2;
		const int tieFighterExplode50AudioPin = 3;
		const int tieFighterShoots80AudioPin  = 4;
		const int tieFighterShoots60AudioPin  = 5;
		const int tieFighterShoots50AudioPin  = 6;
		
		unsigned long Nextupdate;
		unsigned long deathStarExplodeEndTime;
		unsigned long tieFighterExplodeEndTime;
		unsigned long tieFighterShootsEndTime;

		ModeSwitch* pMyModeSwitch;
		
		
        // mode settings as inteded 	
		// mode 0 = debug / CLARE
		// mode 1 = 100/80/80  100% deathStarExplode / 80% tieFighterExplode / 80% tieFighterShoots
		// mode 2 = 100/80/60
		// mode 3 = 100/80/50
		// mode 4 = 100/60/60
		// mode 5 = 100/60/50
		

		void endDeathStarExplodes();
		void endTieFighterExplodes();
		void endTieFighterShoots();
		int getDeathStarExplodePin();
		int getTieFighterExplodesPin();
		int getTieFighterShootsPin();
		

	public:
		void setup(ModeSwitch* pModeSwitch);
		void update();
		void deathStarExplodes();
		void tieFighterExplodes();
		void tieFighterShoots();
		void deathStartExplodes();
		void endDeathStartExplodes();
		
		
		
		
	
};

#endif  //SOUNDBOARD_H
