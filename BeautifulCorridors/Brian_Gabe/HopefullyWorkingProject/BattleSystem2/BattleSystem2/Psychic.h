#ifndef PSYCHIC_H
#define PSYCHIC_H

#include "Move.h"

struct Psychic : public Move
{
	Psychic()
	{
		mName = "Psychic";
		mType = Type::psychic;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 90;
		mAccuracy = 100;
		mPP = 10;
		isSpecial = true;
	};
};

#endif