
#include <stdint.h>

#ifndef SCEENBASE_H
#define SCEENBASE_H



/**
  * class SceenBase
  * 
  */

class SceenBase
{
private:
  uint8_t step;


  void initAttributes () ;


public:



  /**
   * Empty Constructor
   */
  SceenBase ();

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

  /**
   * Set the value of step
   * current and next step
   * @param new_var the new value of step
   */
  void setStep (uint8_t new_var)   {
      step = new_var;
  }

  /**
   * Get the value of step
   * current and next step
   * @return the value of step
   */
  uint8_t getStep ()   {
    return step;
  }



};

#endif // SCEENBASE_H
