#ifndef BATTLE_SYSTEM
#define BATTLE_SYSTEM

class Pokemon;

class BattleSystem
{
public:
	BattleSystem(Pokemon* player1, Pokemon* player2);
	~BattleSystem();

	bool update();

	void getInput();

	void player1Turn();
	void player2Turn();

private:
	bool mBattleOver;
	int mPlayerMove;

	Pokemon* mpPlayer1;
	Pokemon* mpPlayer2;
};

#endif