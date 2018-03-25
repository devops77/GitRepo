#include "Actor.h"

// Constructors/Destructors
//  

Actor::Actor () {
	initAttributes();
}

Actor::~Actor () { }



/**
 * Set the value of sceen
 * @param new_var the new value of sceen
 */
void Actor::setSceen (uint8_t new_var)   {
    sceen = new_var;
}

/**
 * Get the value of sceen
 * @return the value of sceen
 */
uint8_t Actor::getSceen ()   {
  return sceen;
}

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



