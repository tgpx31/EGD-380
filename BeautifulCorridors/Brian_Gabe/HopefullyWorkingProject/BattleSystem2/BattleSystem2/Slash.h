#ifndef SLASH_H
#define SLASH_H

#include "Slash.h"

struct Slash : public Move
{
	Slash()
	{
		mName = "Slash";
		mType = Type::normal;
		mPower = 70;
		mAccuracy = 100;
		mPP = 20;
		isSpecial = false;
	};
};

#endif