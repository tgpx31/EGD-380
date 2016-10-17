#include "Charizard.h"
#include "Slowbro.h"

int main()
{
	// need to seed for random
	srand(time(NULL));

	// Test variables
	Charizard* testChar1 = new Charizard();
	Slowbro* testBro1 = new Slowbro();

	testBro1->useMove(0, testChar1);
	testBro1->useMove(0, testChar1);
	testBro1->useMove(0, testChar1);

	delete testChar1;
	delete testBro1;

	std::cin.get();
	return 0;
}