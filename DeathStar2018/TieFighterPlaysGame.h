/*
 * TieFighterPlaysGame.h
 *
 *  Created on: Mar 30, 2018
 *      Author: BigDaddy
 */

#ifndef TIEFIGHTERPLAYSGAME_H_
#define TIEFIGHTERPLAYSGAME_H_

#include <stdint.h>
#include "TieFighter.h"
#include "SceenBase.h"

enum class TieFighterPlayGameSteps { WaitToShoot, StartLazer, FadeLazer, ShotDown };



class TieFighterPlaysGame: public SceenBase {

private:
	TieFighter* pFighter;
	TieFighterPlayGameSteps nextStep;
	uint8_t laserBrightness;
public:
	TieFighterPlaysGame();
	virtual ~TieFighterPlaysGame();

	void linkFighter(TieFighter* newFighter);



	/**
	   * init the vars when this script starts
	   * set step = 0
	   * updat = now
	   */
	void startSceen ();


	  /**
	   * will decide when and what to do
	   * think this will be a big switch based on step value
	   */
	void run ();



	void doWaitToShootStep();
	void doStartLazerStep();
	void doFadeLaserStep();
	void doShotDownStep();




};

#endif /* TIEFIGHTERPLAYSGAME_H_ */
