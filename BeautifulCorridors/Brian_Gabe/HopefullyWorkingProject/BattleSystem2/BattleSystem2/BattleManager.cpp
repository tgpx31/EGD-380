#include "BattleManager.h"
#include "Pokemon.h"
#include <iostream>

BattleSystem::BattleSystem(Pokemon* p1poke1, Pokemon* p1poke2, Pokemon* p2poke1, Pokemon* p2poke2)
{
	//populate pokemon rosters
	mpP1Roster[0] = p1poke1;
	mpP1Roster[1] = p1poke2;
	
	mpP2Roster[0] = p2poke1;
	mpP2Roster[1] = p2poke2;

	//set active pokemon to first in roster arrays
	mpPlayer1 = mpP1Roster[0];
	mpPlayer2 = mpP2Roster[0];

	mUpdating = true;
}

BattleSystem::~BattleSystem()
{
	for (auto it : mpP1Roster)
		delete it;

	for (auto it : mpP2Roster)
		delete it;
}

bool BattleSystem::update()
{
	mPokemonFainted = false;//need this bool for turn logic

	getInput();

	if (mpPlayer1->getSpeed() > mpPlayer2->getSpeed() || mP1Fighting == false)
	{
		player1Turn();

		if (!mPokemonFainted) //avoids enemy getting a free hit in after losing a pokemon
			player2Turn();
	}
	else
	{
		player2Turn();

		if (!mPokemonFainted)
			player1Turn();
	}

	return mUpdating;
}

void BattleSystem::getInput()
{
	system("CLS");
	std::cout << mpPlayer1->getName() << " VS. " << mpPlayer2->getName() << std::endl;

	std::cout << "\nWhat will you do?\nFight[0] Switch[1]\n";
	std::cin >> mPlayerMove;

	if (mPlayerMove == 0)//player chose to fight
	{
		mP1Fighting = true;

		std::cout << "\nYour move: What should " << mpPlayer1->getName() << " do?\n";
		mpPlayer1->displayMoveList();
		std::cin >> mPlayerMove;
	}
	else //player chose to switch
	{
		mP1Fighting = false;
		player1PromptSwitch();
	}
}

void BattleSystem::player1Turn()
{
	if (mP1Fighting)
	{
		player1Attack();
	}
	else
	{
		player1Switch();
	}
}

void BattleSystem::player2Turn()
{
	//this is redundant I know, in the future this would be more complex with enemy AI
	player2Attack();
}

void BattleSystem::player1Attack()
{
	if (mPlayerMove < 0)
	{
		mUpdating = false;
		return;
	}
	else if (mPlayerMove >= 0 && mPlayerMove <= 3)
	{
		mpPlayer1->useMove(mPlayerMove, mpPlayer2);
	}

	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();

	if (mpPlayer2->didFaint()) //attack killed enemy pokemon
	{
		mPokemonFainted = true;

		if (p2RosterDead()) //battle over
		{
			std::cout << "You Win!\n";
			std::cin.get();
			mUpdating = false;
			return;
		}
		else //switch to next pokemon
		{
			player2PromptSwitch();
			player2Switch();
		}
	}
}

void BattleSystem::player1Switch()
{
	if (mPlayerMove < 0 || mPlayerMove > 1) //out of range
	{
		mUpdating = false;
		return;
	}
	else
	{
		mpPlayer1 = mpP1Roster[mPlayerMove];
		std::cout << "\nYou switched to " << mpPlayer1->getName() << "!\n";
	}

	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();
}

void BattleSystem::player1PromptSwitch()
{
	bool exit = false;
	while (!exit)
	{
		std::cout << "\nWhat Pokemon will you switch to?\n";
		displayP1Roster();
		std::cin >> mPlayerMove;

		if (mpP1Roster[mPlayerMove]->didFaint())
		{
			std::cout << "\nThat Pokemon is fainted! Try again.\n";
		}
		else
		{
			exit = true;
		}
	}	
}

void BattleSystem::player2Attack()
{
	mCompInput = randomNumber(0, 3);
	mpPlayer2->useMove(mCompInput, mpPlayer1);

	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();

	if (mpPlayer1->didFaint()) //attack killed enemy pokemon
	{
		mPokemonFainted = true;

		if (p1RosterDead()) //battle over
		{
			std::cout << "Player 2 Wins!\n";
			std::cin.get();
			mUpdating = false;
			return;
		}
		else //switch to next pokemon
		{
			player1PromptSwitch();
			player1Switch();
		}
	}
}

void BattleSystem::player2Switch()
{
	mpPlayer2 = mpP2Roster[mCompInput];
	std::cout << "\nThe Enemy switched to " << mpPlayer2->getName() << "!\n";

	std::cout << "\nPress ENTER to continue\n";
	std::cin.get();
}

void BattleSystem::player2PromptSwitch()
{
	bool exit = false;
	while (!exit)
	{
		mCompInput = randomNumber(0, 1);

		if (mpP2Roster[mCompInput]->didFaint())
		{
			//computer will try again
		}
		else
		{
			exit = true;
		}
	}
}

void BattleSystem::displayP1Roster()
{
	int pokeNum = 0;
	for (auto poke : mpP1Roster)
	{
		std::cout << poke->getName() << "[" << pokeNum << "] ";
		++pokeNum;
	}
	std::cout << std::endl;
}

bool BattleSystem::p1RosterDead()
{
	bool defeated = true;

	for (Pokemon* poke : mpP1Roster)
	{
		if (!poke->didFaint())
		{
			defeated = false;
			break;
		}
	}

	return defeated;
}

bool BattleSystem::p2RosterDead()
{

	bool defeated = true;

	for (Pokemon* poke : mpP2Roster)
	{
		if (!poke->didFaint())
		{
			defeated = false;
			break;
		}
	}

	return defeated;
}