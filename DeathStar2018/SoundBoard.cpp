#define DEBUG
#include "Arduino.h"
#include "global.h"  //global defines
#include "SoundBoard.h"

		const int myBasePin = 6;  // pin for lowest trigger
		
		const int deathStarExplodeAudioPin = 0;
		const int tieFighterExplode80AudioPin = 1;
		const int tieFighterExplode60AudioPin = 2;
		const int tieFighterExplode50AudioPin = 3;
		const int tieFighterShoots80AudioPin  = 4;
		const int tieFighterShoots60AudioPin  = 5;
		const int tieFighterShoots50AudioPin  = 6;
		
        // mode settings as inteded 	
		// mode 0 = debug / CLARE
		// mode 1 = 100/80/80  100% deathStarExplode / 80% tieFighterExplode / 80% tieFighterShoots
		// mode 2 = 100/80/60
		// mode 3 = 100/80/50
		// mode 4 = 100/60/60
		// mode 5 = 100/60/50
		

		void SoundBoard::setup(ModeSwitch* pModeSwitch)
		{
			pMyModeSwitch = pModeSwitch;
			for(uint8_t i=0; i<8; i++)
			{
				pinMode(myBasePin+i, OUTPUT);
				digitalWrite(myBasePin+i,HIGH);  // need voltage high so it does not trigger
			}
			
			deathStarExplodeEndTime = END_OF_TIME;
			tieFighterExplodeEndTime = END_OF_TIME;
			tieFighterShootsEndTime = END_OF_TIME;
		}		
		
		/***
		** check to see if we need to turn off any triggers after 200 ms
		**/ 
		void SoundBoard::update()
		{
			unsigned long now = millis();
			// if we get here we have work to do
			if( deathStarExplodeEndTime < now)
			{
				endDeathStartExplodes();
			}
			if( tieFighterExplodeEndTime < now)
			{
				endTieFighterExplodes();
			}
			if( tieFighterShootsEndTime  < now)
			{
				endTieFighterShoots();
			}
			
					
		}		
		
		
		
		void SoundBoard::deathStarExplodes()
		{
			// start sound first
			digitalWrite(getDeathStarExplodePin(), LOW);   // trigger sound
			deathStarExplodeEndTime = millis()+ triggerDownTime;   // when the trigger must go up
		}		
		
		void SoundBoard::endDeathStartExplodes()
		{
			digitalWrite(getDeathStarExplodePin(), HIGH);   // trigger end
			deathStarExplodeEndTime = END_OF_TIME;
		}		
		
		void SoundBoard::tieFighterExplodes()
		{
			digitalWrite(getTieFighterExplodesPin(), LOW);   // trigger sound
			tieFighterExplodeEndTime = millis()+ triggerDownTime;   // when the trigger must go up
		}		
		
		void SoundBoard::endTieFighterExplodes()
		{
			digitalWrite(getTieFighterExplodesPin(), HIGH);   // trigger end
			tieFighterExplodeEndTime = END_OF_TIME;   
		}
		
		void SoundBoard::tieFighterShoots()
		{
			digitalWrite(getTieFighterShootsPin(), LOW);   // trigger sound
			tieFighterShootsEndTime = millis()+ triggerDownTime;   // when the trigger must go up
			
		}
		
		void SoundBoard::endTieFighterShoots()
		{
			digitalWrite(getTieFighterShootsPin(), HIGH);   // trigger end
			tieFighterShootsEndTime = END_OF_TIME;   // when the trigger must go up
			
		}		
		
		
		
        // mode settings as inteded 	
		// mode 0 = debug / CLARE
		// mode 1 = 100/80/80   0/1/3   100% deathStarExplode / 80% tieFighterExplode / 80% tieFighterShoots
		// mode 2 = 100/80/60   0/1/4
		// mode 3 = 100/80/50   0/1/5
		// mode 4 = 100/60/60   0/2/4
		// mode 5 = 100/60/50   0/2/5
		
		int SoundBoard::getDeathStarExplodePin()
		{
				return myBasePin; // always have as loudes
		}
		
		int SoundBoard::getTieFighterExplodesPin()
		{
			int myPin = 1;  // assume 80% default
			switch( pMyModeSwitch->getCurrentModeNow() )
			{
				case 1: 
				case 2: 
				case 3: 
					// 80%
					myPin = 1;
					break;
				case 4:
				case 5:
					//60%
					myPin = 2;
					break;
				default:
					myPin = 1;
					
			}
			return myPin;
		}
		
		
		int SoundBoard::getTieFighterShootsPin()
		{
			int myPin = 4;  // assume 60% default
			switch( pMyModeSwitch->getCurrentModeNow() )
			{
				case 1: 
					// 80%
					myPin = 3;
					break;
				case 2: 
				case 4:
					//60%
					myPin = 4;
					break;
				case 3: 
				case 5:
					//50%
					myPin = 5;
					break;
				default:
					myPin = 1;
					
			}
			return myPin;
			
		}

		
		
	


