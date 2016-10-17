#ifndef SURF_H
#define SURF_H

#include "Move.h"

struct Surf : public Move
{
	Surf()
	{
		mName = "Surf";
		mType = Type::water;
		mPower = 95;
		mAccuracy = 100;
		mPP = 15;
		isSpecial = true;
	};
};

#endif