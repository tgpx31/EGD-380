#ifndef SLOWBRO_H
#define SLOWBRO_H

#include "Pokemon.h"

#include "Surf.h"
#include "SlackOff.h"
#include "Agility.h"
#include "IceBeam.h"

class Slowbro : public Pokemon
{
public:
	Slowbro()
	{
		mName = "Slowbro";

		mMaxHealth = 394;
		mCurrentHealth = mMaxHealth;
		mAttack = 167;
		mDefense = 350;
		mSpAttack = 237;
		mSpDefense = 196;
		mSpeed = 96;

		mpMoveList[0] = new Surf();
		mpMoveList[1] = new SlackOff();
		mpMoveList[2] = new Agility();
		mpMoveList[3] = new IceBeam();

		mType[0] = Type::water;
		mType[1] = Type::psychic;
	};

private:
};

#endif