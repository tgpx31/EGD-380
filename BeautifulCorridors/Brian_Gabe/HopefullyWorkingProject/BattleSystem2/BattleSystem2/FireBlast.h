#ifndef FIREBLAST_H
#define FIREBLAST_H

#include "Move.h"

struct FireBlast : public Move
{
	FireBlast()
	{
		mName = "Fire Blast";
		mType = Type::fire;
		mPower = 110;
		mAccuracy = 85;
		mPP = 5;
		isSpecial = true;
	};
};

#endif