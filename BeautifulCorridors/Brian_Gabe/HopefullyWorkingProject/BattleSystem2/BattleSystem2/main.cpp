#include "Charizard.h"
#include "Slowbro.h"
#include "BattleManager.h"

int main()
{
	// need to seed for random
	srand(static_cast<int>(time(NULL)));
	int input = 0;
	int compInput = 0;

	// Test variables
	Charizard* testChar1 = new Charizard();
	Slowbro* testBro1 = new Slowbro();

	BattleSystem testSystem(testBro1, testChar1);

	while (testSystem.update())
	{
		//continue battle loop
	}

	return 0;
}