#ifndef LICK
#define LICK

#include "Move.h"

struct Lick : public Move
{
	Lick()
	{
		mName = "Lick";
		mType = Type::ghost;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 30;
		mAccuracy = 100;
		mPP = 30;
		isSpecial = false;
	};
};

#endif