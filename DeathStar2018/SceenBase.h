
#include <stdint.h>
#include "Arduino.h"

#ifndef SCEENBASE_H
#define SCEENBASE_H



/**
  * class SceenBase
  * 
  */

class SceenBase
{
protected:
	unsigned long nextUpdate = 0; // force to happen right away
	int stepIterationCount;
	bool mySeenIsDone;


  void initAttributes () ;


public:

  SceenBase();


  unsigned long getNextUpdate()
  {
	  return nextUpdate;
  }

  /**
   * Empty Destructor
   */
  virtual ~SceenBase ();


  /**
   * called to start a screen as part of sceen change
   */
  virtual void startSceen () = 0;


  /**
   * called by actor, runst the current step
   */
  virtual void run () =0;

  bool sceenDone();




};

#endif // SCEENBASE_H
