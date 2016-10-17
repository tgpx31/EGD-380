#ifndef SLACKOFF_H
#define SLACKOFF_H

#include "Move.h"

struct SlackOff : public Move
{
	SlackOff()
	{
		mName = "Slack Off";
		mType = Type::normal;
		mPower = -1;
		mAccuracy = 100;
		mPP = 10;
		isSpecial = false;
	};
};

#endif