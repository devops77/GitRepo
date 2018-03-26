
#include <stdint.h>

#ifndef SCEENBASE_H
#define SCEENBASE_H



/**
  * class SceenBase
  * 
  */

class SceenBase
{
protected:
  time nextUpdate = 0; // force to happen right away
  int stepIterationCount;


  void initAttributes () ;


public:

  SceenBase();


  time getNextUpdate()
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
  virtual void start () = 0;


  /**
   * called by actor, runst the current step
   */
  virtual void run () =0;





};

#endif // SCEENBASE_H
