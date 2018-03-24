

#include <stdint.h>


#ifndef TIEFIGHTEREXPLODE_H
#define TIEFIGHTEREXPLODE_H
#include "SceenBase.h"
#include "TieFighter.h"


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

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * sets up linkage to the owner class
   * @param  new_parameter
   */
  void setup_ (TieFighter * new_parameter)
  {
  }


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
  TieFighter * tieFighter;
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

  /**
   * Set the value of tieFighter
   * points to the owner, set in setyp
   * @param new_var the new value of tieFighter
   */
  void setTieFighter (TieFighter * new_var)   {
      tieFighter = new_var;
  }

  /**
   * Get the value of tieFighter
   * points to the owner, set in setyp
   * @return the value of tieFighter
   */
  TieFighter * getTieFighter ()   {
    return tieFighter;
  }
private:


  void initAttributes () ;

};

#endif // TIEFIGHTEREXPLODE_H
