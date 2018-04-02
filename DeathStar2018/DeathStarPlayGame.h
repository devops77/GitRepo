/*
 * DeathStarPlayGame.h
 *
 *  Created on: Apr 1, 2018
 *      Author: BigDaddy
 */

#include <stdint.h>
#include "VentPort.h"

#ifndef DEATHSTARPLAYGAME_H_
#define DEATHSTARPLAYGAME_H_

#include "SceenBase.h"

// order of steps
enum class DeathStarPlayGameSteps { PlayGame, FinalState };

class DeathStarPlayGame: public SceenBase {
private:
	// keeps track of what step we are on
	VentPort* pVentPort;
	DeathStarPlayGameSteps nextStep;

public:
	DeathStarPlayGame();
	virtual ~DeathStarPlayGame();

	void linkVentPort(VentPort* newPort);

	/**
	 * init the vars when this script starts
	 * set step = 0
	 * updat = now
	 */
	virtual void startSceen();
	/**
	 * think this will be a big switch based on step value
	 */
	virtual void run();

	void doChase();

};

#endif /* DEATHSTARPLAYGAME_H_ */
