#ifndef CRUNCH
#define CRUNCH

#include "Move.h"

struct Crunch : public Move
{
	Crunch()
	{
		mName = "Crunch";
		mType = Type::dark;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 80;
		mAccuracy = 100;
		mPP = 15;
		isSpecial = false;
	};
};

#endif