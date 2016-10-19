#include "BattleManager.h"
#include "Pokemon.h"
#include <iostream>

BattleSystem::BattleSystem(Pokemon* player1, Pokemon* player2)
{
	mpPlayer1 = player1;
	mpPlayer2 = player2;
	mBattleOver = false;
}

BattleSystem::~BattleSystem()
{
	delete mpPlayer1;
	delete mpPlayer2;
}

bool BattleSystem::update()
{
	getInput();

	if (mpPlayer1->getSpeed() > mpPlayer2->getSpeed())
	{
		player1Turn();
		player2Turn();
	}
	else
	{
		player2Turn();
		player1Turn();
	}

	return mBattleOver;
}

void BattleSystem::getInput()
{
	system("CLS");
	std::cout << mpPlayer1->getName() << " VS. " << mpPlayer2->getName() << std::endl;

	std::cout << "\nYour move: What should Slowbro do?\n";
	mpPlayer1->displayMoveList();

	std::cin >> mPlayerMove;
}

void BattleSystem::player1Turn()
{
	if (mPlayerMove < 0)
	{
		mBattleOver = true;
		return;
	}
	else if (mPlayerMove >= 0 && mPlayerMove <= 3)
	{
		mpPlayer1->useMove(mPlayerMove, mpPlayer2);
	}
		
	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();
	std::cin.get();

	if (mpPlayer2->didFaint())
		mBattleOver = true;
}

void BattleSystem::player2Turn()
{
	int compInput = randomNumber(0, 3);
	mpPlayer2->useMove(compInput, mpPlayer1);

	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();

	if (mpPlayer1->didFaint())
		mBattleOver = true;
}