#ifndef DEFENSE_CURL
#define DEFENSE_CURL

#include "Move.h"

struct DefenseCurl : public Move
{
	DefenseCurl()
	{
		mName = "Defense Curl";
		mType = Type::normal;

		mMoveAction = stat_change;
		mAffectedStatIndex = 1;
		mStatMultiplier = 1.5f;

		mPower = 0;
		mAccuracy = 100;
		mPP = 30;
		isSpecial = true;
	}
};

#endif