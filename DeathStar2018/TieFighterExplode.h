

#include <stdint.h>
#include "SceenBase.h"



#ifndef TIEFIGHTEREXPLODE_H
#define TIEFIGHTEREXPLODE_H

/**
  * class TieFighterExplode
  * 
  */

class TieFighterExplode : public SceenBase
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  TieFighterExplode ();

  /**
   * Empty Destructor
   */
  virtual ~TieFighterExplode ();




  /**
   * init the vars when this script starts
   * set step = 0
   * updat = now
   */
  void start ()
  {
  }


  /**
   * think this will be a big switch based on step value
   */
  void run ()
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  // keeps track of what step we are on
  uint8_t step;
  // points to the owner, set in setyp

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of step
   * keeps track of what step we are on
   * @param new_var the new value of step
   */
  void setStep (uint8_t new_var)   {
      step = new_var;
  }

  /**
   * Get the value of step
   * keeps track of what step we are on
   * @return the value of step
   */
  uint8_t getStep ()   {
    return step;
  }


private:


  void initAttributes () ;

};

#endif // TIEFIGHTEREXPLODE_H
