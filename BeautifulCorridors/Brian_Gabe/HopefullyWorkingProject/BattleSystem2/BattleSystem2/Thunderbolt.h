#ifndef THUNDERBOLT
#define THUNDERBOLT

#include "Move.h"

struct Thunderbolt : public Move
{
	Thunderbolt()
	{
		mName = "Thunderbolt";
		mType = Type::electric;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 95;
		mAccuracy = 100;
		mPP = 15;
		isSpecial = true;
	};
};

#endif