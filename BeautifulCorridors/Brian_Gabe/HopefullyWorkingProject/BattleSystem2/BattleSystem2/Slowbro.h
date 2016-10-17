#ifndef SLOWBRO_H
#define SLOWBRO_H

#include "Pokemon.h"

#include "Surf.h"
#include "SlackOff.h"
#include "Psychic.h"
#include "IceBeam.h"

class Slowbro : public Pokemon
{
	Slowbro()
	{
		mName = "Slowbro";

		mHealth = 394;
		mAttack = 249;
		mDefense = 319;
		mSpAttack = 299;
		mSpDefense = 259;
		mSpeed = 159;

		mpMoveList[0] = new Surf();
		mpMoveList[1] = new SlackOff();
		mpMoveList[2] = new Psychic();
		mpMoveList[3] = new IceBeam();

		mType[0] = Type::water;
		mType[1] = Type::psychic;
	};
};

#endif