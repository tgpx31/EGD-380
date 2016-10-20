#ifndef SLACKOFF_H
#define SLACKOFF_H

#include "Move.h"

struct SlackOff : public Move
{
	SlackOff()
	{
		mName = "Slack Off";
		mType = Type::normal;

		mMoveAction = heal;
		mAffectedStatIndex = 0;
		mStatMultiplier = 0;

		mPower = 0;
		mAccuracy = 100;
		mPP = 10;
		isSpecial = false;
	};
};

#endif