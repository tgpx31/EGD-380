#include "Pokemon.h"

void Pokemon::useMove(int index, Pokemon* target)
{
	// Can they actually use the move?
	if (moveList[index]->mPP <= 0) { return; }

	// Will the move hit?
	// check the accuracy, calculate if hit is success

		// Calculate the damage and apply to other
		doDamage(moveList[index], target);
		// reduce the PP of the move
		--moveList[index]->mPP;
		if (moveList[index]->mPP <= 0)
			moveList[index]->mPP = 0;
}

void Pokemon::doDamage(Move* move, Pokemon* Other)
{
	int damage;
	float weakness = 0;
	float STAB_MULT = 1;

	// Random number between 85 and 100
	float randNumber = randomNumber(MIN_RAND_NUM, MAX_RAND_NUM);

	// Check the move used
	// What's it's power?
	// Is it the same type as the Pokemon using it?
	if (move->mType == mType)
		STAB_MULT = 1.5f;
	else
		STAB_MULT = 1;
	// Is the Other Pokemon weak or resistant?

	//((((2 * Level / 5 + 2) * AttackStat * AttackPower / DefenseStat) / 50) + 2) * STAB * Weakness / Resistance * RandomNumber / 100
	if (move->isSpecial)
		damage = ((((2 * LEVEL / 5 + 2) * getSpAttack() * move->mPower / getSpDefence()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100;
	else
		damage = ((((2 * LEVEL / 5 + 2) * getAttack() * move->mPower / getDefence()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100;

	Other->modifyHealth(damage);
}

int Pokemon::randomNumber(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}
