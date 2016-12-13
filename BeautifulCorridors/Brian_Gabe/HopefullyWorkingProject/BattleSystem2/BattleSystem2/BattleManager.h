#ifndef BATTLE_SYSTEM
#define BATTLE_SYSTEM

class Pokemon;

class BattleSystem
{
public:
	BattleSystem(Pokemon* p1poke1, Pokemon* p1poke2, Pokemon* p2poke1, Pokemon* p2poke2);
	~BattleSystem();

	bool update();

	void getInput();

	void player1Turn();
	void player2Turn();

	void player1Attack();
	void player1Switch();
	void player1PromptSwitch();

	void player2Attack();
	void player2Switch();
	void player2PromptSwitch();

	void displayP1Roster();

	bool p1RosterDead();
	bool p2RosterDead();

private:
	bool mUpdating;
	bool mP1Fighting;
	bool mPokemonFainted;
	int mPlayerMove;
	int mCompInput;

	Pokemon* mpPlayer1;
	Pokemon* mpPlayer2;

	Pokemon* mpP1Roster[2];
	Pokemon* mpP2Roster[2];
};

#endif