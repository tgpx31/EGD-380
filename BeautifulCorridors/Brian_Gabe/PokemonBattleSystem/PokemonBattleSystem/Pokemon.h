#ifndef POKEMON_H
#define POKEMON_H

#include "Type.h"
#include "Move.h"

#include <string>

class Pokemon
{
public:
	inline int getHealth() { return mHealth; };
	inline int getAttack() { return mAttack; };
	inline int getSpAttack() { return mSpAttack; };
	inline int getDefence() { return mDefence; };
	inline int getSpDefence() { return mSpDefence; };
	inline int getSpeed() { return mSpeed; };

	inline Move& getMove(int moveNum) { return moveList[moveNum]; };

	inline Type getType() { return mType; };

private:
	std::string mName;

	int mHealth;
	int mAttack;
	int mSpAttack;
	int mDefence;
	int mSpDefence;
	int mSpeed;

	Move moveList[4];
	Type mType;
}

#endif