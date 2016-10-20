#ifndef SNORLAX_H
#define SNORLAX_H

#include "Pokemon.h"

#include "Crunch.h"
#include "Lick.h"
#include "DefenseCurl.h"
#include "BodySlam.h"

class Snorlax : public Pokemon
{
public:
	Snorlax()
	{
		mName = "Snorlax";

		mMaxHealth = 524;
		mCurrentHealth = mMaxHealth;
		mAttack = 319;
		mDefense = 200;
		mSpAttack = 150;
		mSpDefense = 300;
		mSpeed = 65;

		mpMoveList[0] = new Crunch();
		mpMoveList[1] = new Lick();
		mpMoveList[2] = new DefenseCurl();
		mpMoveList[3] = new BodySlam();

		mType[0] = Type::normal;
		mType[1] = Type::NONE;
	};

private:
};

#endif