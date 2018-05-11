/*
 * MoreCode.h
 *
 *  Created on: Apr 11, 2018
 *      Author: BigDaddy
 */

#include <stdint.h>
#include "VentPort.h"
#include "DeathStarFace.h"


#ifndef MORSECODE_H_
#define MORSECODE_H_

#include "SceenBase.h"

enum class MoresCodeSteps { PlayCode, Flash, FadeToBlack };



class MorseCode: public SceenBase {

private:
	VentPort* pVentPort;
	DeathStarFace* pDeathStarFace;
	MoresCodeSteps nextStep;
	unsigned long stepStartTime;
	int change;


public:
	MorseCode();
	virtual ~MorseCode();


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



	void dot();
	void dash();
	void wordPause();
	void letterPause();
	void doFlash();
	void doFadeToBlack();



};

#endif /* MORECODE_H_ */
