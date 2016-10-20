#ifndef BITE_H
#define BITE_H

#include "Move.h"

struct Bite : public Move
{
	Bite()
	{
		mName = "Bite";
		mType = Type::dark;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 60;
		mAccuracy = 100;
		mPP = 25;
		isSpecial = false;
	};
};

#endif