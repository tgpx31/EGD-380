#ifndef PSYCHIC_H
#define PSYCHIC_H

#include "Move.h"

struct Psychic : public Move
{
	Psychic()
	{
		mName = "Psychic";
		mType = Type::psychic;
		mPower = 90;
		mAccuracy = 100;
		mPP = 10;
		isSpecial = true;
	};
};

#endif