#ifndef BODY_SLAM
#define BODY_SLAM

#include "Move.h"

struct BodySlam : public Move
{
	BodySlam()
	{
		mName = "Body Slam";
		mType = Type::normal;

		mMoveAction = damage;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 85;
		mAccuracy = 100;
		mPP = 15;
		isSpecial = false;
	};
};

#endif