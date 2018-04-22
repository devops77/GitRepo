#include "SceenBase.h"

// Constructors/Destructors
//  

SceenBase::SceenBase ()
{
	mySeenIsDone=false;  // assume not true
	initAttributes();

}

SceenBase::~SceenBase () { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void SceenBase::initAttributes () {
}

bool SceenBase::sceenDone()
{
	return mySeenIsDone;
}


