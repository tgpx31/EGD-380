#include "Charizard.h"
#include "Slowbro.h"
#include "Raichu.h"
#include "Snorlax.h"

#include "BattleManager.h"

int main()
{
	// need to seed for random
	srand(static_cast<int>(time(NULL)));
	int input = 0;
	int compInput = 0;

	// Test variables
	Charizard* poke1= new Charizard();
	Slowbro* poke2 = new Slowbro();
	Snorlax* poke3 = new Snorlax();
	Raichu* poke4 = new Raichu();

	BattleSystem testSystem(poke2, poke4, poke1, poke3);

	while (testSystem.update())
	{
		//continue battle loop
	}

	return 0;
}