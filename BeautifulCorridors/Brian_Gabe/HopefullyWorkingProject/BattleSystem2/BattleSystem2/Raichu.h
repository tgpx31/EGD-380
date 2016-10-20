#ifndef RAICHU
#define RAICHU

#include "Pokemon.h"

#include "Thunderbolt.h"
#include "Agility.h"
#include "BodySlam.h"
#include "DefenseCurl.h"

class Raichu : public Pokemon
{
public:
	Raichu()
	{
		mName = "Raichu";

		mMaxHealth = 324;
		mCurrentHealth = mMaxHealth;
		mAttack = 200;
		mDefense = 180;
		mSpAttack = 279;
		mSpDefense = 259;
		mSpeed = 319;

		mpMoveList[0] = new Thunderbolt();
		mpMoveList[1] = new Agility();
		mpMoveList[2] = new DefenseCurl();
		mpMoveList[3] = new BodySlam();

		mType[0] = Type::electric;
		mType[1] = Type::NONE;
	};

private:
};

#endif