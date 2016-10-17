#ifndef AIRCUTTER_H
#define AIRCUTTER_H

#include "Move.h"

struct AirCutter : public Move
{
	AirCutter()
	{
		mName = "Air Cutter";
		mType = Type::flying;
		mPower = 60;
		mAccuracy = 95;
		mPP = 25;
		isSpecial = true;
	};
};

#endif