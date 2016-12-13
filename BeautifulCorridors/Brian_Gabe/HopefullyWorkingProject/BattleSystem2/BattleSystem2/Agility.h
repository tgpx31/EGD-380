#ifndef AGILITY_H
#define AGILITY_H

#include "Move.h"

struct Agility : public Move
{
	Agility()
	{
		mName = "Agility";
		mType = Type::psychic;

		mMoveAction = stat_change;
		mAffectedStatIndex = 4;
		mStatMultiplier = 2.0f;

		mPower = 0;
		mAccuracy = 100;
		mPP = 30;
		isSpecial = true;
	}
};

#endif