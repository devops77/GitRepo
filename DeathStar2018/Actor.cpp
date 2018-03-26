#include "Actor.h"

// Constructors/Destructors
//  

Actor::Actor () {

}


Actor::~Actor () { }



/**
 * Set the value of nextUpdate
 * @param new_var the new value of nextUpdate
 */
void Actor::setNextUpdate (uint32_t new_var)   {
    nextUpdate = new_var;
}

/**
 * Get the value of nextUpdate
 * @return the value of nextUpdate
 */
uint32_t Actor::getNextUpdate ()   {
  return nextUpdate;
}



