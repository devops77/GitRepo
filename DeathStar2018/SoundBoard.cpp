/**********************
 *
 * No idea why but not all pins work for sound
 *   tie fighter shoots owrks on Pin ,5,6
 *   Tie fighter explodes works on pin 2,
 */



#define DEBUG
#include "debugArduino.h"

#include "Arduino.h"
#include "global.h"  //global defines
#include "SoundBoard.h"

		const int myBasePin = 0;  // pin for lowest trigger
		
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
			DEBUG_PRINT("setup");
			pMyModeSwitch = pModeSwitch;
			for(uint8_t i=0; i<8; i++)
			{
				int pin = myBasePin+i;
				DB_NAME_VALUE("pin ", pin);
				pinMode(pin, OUTPUT);
				digitalWrite(pin,HIGH);  // need voltage high so it does not trigger
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
			DEBUG_PRINT("Sound");
			digitalWrite(getDeathStarExplodePin(), LOW);   // trigger sound
			deathStarExplodeEndTime = millis()+ triggerDownTime;   // when the trigger must go up
		}		
		
		void SoundBoard::endDeathStartExplodes()
		{
			DEBUG_PRINT("Sound");
			digitalWrite(getDeathStarExplodePin(), HIGH);   // trigger end
			deathStarExplodeEndTime = END_OF_TIME;
		}		
		
		void SoundBoard::tieFighterExplodes()
		{
			DEBUG_PRINT("Sound");
			int pin = getTieFighterExplodesPin();
			DB_NAME_VALUE("pin ", pin);

			digitalWrite(pin, LOW);   // trigger sound
			tieFighterExplodeEndTime = millis()+ triggerDownTime;   // when the trigger must go up
		}		
		
		void SoundBoard::endTieFighterExplodes()
		{
			DEBUG_PRINT("Sound");
			digitalWrite(getTieFighterExplodesPin(), HIGH);   // trigger end
			tieFighterExplodeEndTime = END_OF_TIME;   
		}
		
		void SoundBoard::tieFighterShoots()
		{
			DEBUG_PRINT("Sound");
			int pin = getTieFighterShootsPin();
			DB_NAME_VALUE("pin ", pin);

			digitalWrite(pin, LOW);   // trigger sound
			tieFighterShootsEndTime = millis()+ triggerDownTime;   // when the trigger must go up
			
		}
		
		void SoundBoard::endTieFighterShoots()
		{
			DEBUG_PRINT("Sound");
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
			return 2;
			DEBUG_PRINT("Sound");
				return myBasePin; // always have as loudes
		}
		
		int SoundBoard::getTieFighterExplodesPin()
		{
			return 5;


			DEBUG_PRINT("Sound");
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
			return 6;
			//DEBUG_PRINT("Sound");
			int myPin = 4;  // assume 60% default
			switch( pMyModeSwitch->getCurrentModeNow() )
			{
				case 1: 
					// 80%
					myPin = 4;
					break;
				case 2: 
				case 4:
					//60%
					myPin = 5;
					break;
				case 3: 
				case 5:
					//50%
					myPin = 6;
					break;
				default:
					myPin = 4;
					
			}
			return myPin;
			
		}

		
		
	


