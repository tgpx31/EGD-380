#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "Pokemon.h"

#include "FireBlast.h"
#include "Slash.h"
#include "Bite.h"
#include "AirCutter.h"

class Charizard : public Pokemon
{
	Charizard()
	{
		mName = "Charizard";

		mHealth = 360;
		mAttack = 267;
		mDefense = 255;
		mSpAttack = 317;
		mSpDefense = 269;
		mSpeed = 299;

		mpMoveList[0] = new FireBlast();
		mpMoveList[1] = new Slash();
		mpMoveList[2] = new Bite();
		mpMoveList[3] = new AirCutter();

		mType[0] = Type::fire;
		mType[1] = Type::flying;
	};
};

#endif