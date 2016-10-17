#ifndef ICEBEAM_H
#define ICEBEAM_H

#include "Move.h"

struct IceBeam : public Move
{
	IceBeam()
	{
		mName = "Ice Beam";
		mType = Type::ice;
		mPower = 90;
		mAccuracy = 100;
		mPP = 10;
		isSpecial = true;
	};
};

#endif