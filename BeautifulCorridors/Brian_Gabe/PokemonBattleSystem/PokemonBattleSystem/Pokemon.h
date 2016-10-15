#ifndef POKEMON_H
#define POKEMON_H

#include "Type.h"
#include "Move.h"

#include <string>
#include <ctime>

class Pokemon
{
public:
	Pokemon();
	~Pokemon();

	inline void modifyHealth(int change) { mHealth += change; };

	inline int getHealth() { return mHealth; };
	inline int getAttack() { return mAttack; };
	inline int getSpAttack() { return mSpAttack; };
	inline int getDefence() { return mDefence; };
	inline int getSpDefence() { return mSpDefence; };
	inline int getSpeed() { return mSpeed; };

	inline Move* getMove(int moveNum) { return moveList[moveNum]; };

	inline Type getType() { return mType; };

	void useMove(int index, Pokemon* target);
	void doDamage(Move* move, Pokemon* Other);

private:
	std::string mName;

	int mHealth;
	int mAttack;
	int mSpAttack;
	int mDefence;
	int mSpDefence;
	int mSpeed;

	Move* moveList[4];
	Type mType;

	const static int LEVEL = 100;
	const static int MIN_RAND_NUM = 85;
	const static int MAX_RAND_NUM = 100;

	int randomNumber(int min, int max);
}

#endif