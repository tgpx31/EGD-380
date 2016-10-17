#include "Pokemon.h"

Pokemon::~Pokemon()
{
	for (auto i : mpMoveList)
		delete i;
}

void Pokemon::useMove(int index, Pokemon* target)
{
	// Can they actually use the move?
	if (mpMoveList[index]->mPP <= 0) { std::cout << "You're out of PP!\n"; return; }

	// Will the move hit?
	// check the accuracy, calculate if hit is success
	if (mpMoveList[index]->mAccuracy >= randomNumber(MIN_ACCURACY, MAX_RAND_NUM))
	{
		std::cout << mName << " used " << mpMoveList[index]->mName << "!\n";
		// Calculate the damage and apply to other
		doDamage(mpMoveList[index], target);
		// reduce the PP of the move
		--mpMoveList[index]->mPP;
		if (mpMoveList[index]->mPP <= 0)
			mpMoveList[index]->mPP = 0;
	}
	else
	{
		std::cout << "The attack missed!\n";
	}
}

void Pokemon::doDamage(Move* move, Pokemon* Other)
{
	int damage;
	float weakness = 1;
	float STAB_MULT = 1;

	if (move->mPower < 0)
	{
		// These moves heal you
		modifyHealth(-static_cast<int>(getMaxHealth() / 2));
		if (getHealth() > getMaxHealth())
		{
			// Cap at the maxHealth
			modifyHealth(getHealth() - getMaxHealth());
		}
		std::cout << mName << " healed for " << static_cast<int>(getMaxHealth() / 2) << " HP!\n\n";
		return;
	}

	// Random number between 85 and 100
	int randNumber = randomNumber(MIN_RAND_NUM, MAX_RAND_NUM);

	// Check the move used
	// Is it the same type as the Pokemon using it?
	if (move->mType == mType[0] || move->mType == mType[1])
		STAB_MULT = 1.5f;
	else
		STAB_MULT = 1;

	// Is the Other Pokemon weak or resistant?
	weakness = calcResistance(move->mType, Other);
	if (weakness > 1)
		std::cout << "It was SUPER EFFECTIVE!\n";
	else if(weakness < 1 && weakness > 0)
		std::cout << "It wasn't very effective...\n";
	else if (weakness == 0)
	{
		std::cout << "But it did nothing!\n";
		return;
	}
		

	// is the move Special?
	if (move->isSpecial)
		damage = static_cast<int>(((((2 * LEVEL / 5 + 2) * getSpAttack() * move->mPower / getSpDefense()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100);
	else
		damage = static_cast<int>(((((2 * LEVEL / 5 + 2) * getAttack() * move->mPower / getDefense()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100);

	// Deal the damage to the target
	std::cout << mName << " did " << damage << " to " << Other->mName << "!\n";
	Other->modifyHealth(damage);
	if (Other->getHealth() < 0)
	{
		//Other->modifyHealth(-getHealth());
		std::cout << Other->mName << " fainted!\n\n";

		// Declare a winner
	}
	else
		std::cout << Other->mName << " has " << Other->getHealth() << " HP remaining!\n\n";
}

float Pokemon::calcResistance(Type moveType, Pokemon * other)
{
	float finalMult = 1;
	// Compare the moveType to the Pokemons two types
	finalMult *= TypeChart[moveType][other->mType[0]];
	if (other->mType[1] == Type::NONE)
		finalMult *= 1;
	else
		finalMult *= TypeChart[moveType][other->mType[1]];

	return finalMult;
}

void Pokemon::displayMoveList()
{
	int moveNo = 0;
	for (auto move : mpMoveList)
	{
		std::cout << move->mName << "[" << moveNo << "] ";
		++moveNo;
	}
	std::cout << std::endl;
}

int randomNumber(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}
