/*
 * DeathStarPlayGame.h
 *
 *  Created on: Apr 1, 2018
 *      Author: BigDaddy
 */


#include <stdint.h>
#include "VentPort.h"
#include "DeathStarFace.h"

#ifndef DEATHSTARPLAYGAME_H_
#define DEATHSTARPLAYGAME_H_\

#include "SceenBase.h"

// order of steps
enum class DeathStarPlayGameSteps { PlayGame, FinalState };

class DeathStarPlayGame: public SceenBase {
private:
	// keeps track of what step we are on
	VentPort* pVentPort;
	DeathStarFace* pDeathStarFace;
	DeathStarPlayGameSteps nextStep;
	unsigned long stepStartTime;
	unsigned long nextTwinkleTime;
	unsigned long nextFaceFadeTime;
	

public:
	DeathStarPlayGame();
	virtual ~DeathStarPlayGame();

	void linkVentPort(VentPort* newPort);
  void linkDeathStarFace(DeathStarFace* newFace);

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
	void doTwinkle();

};

#endif /* DEATHSTARPLAYGAME_H_ */
