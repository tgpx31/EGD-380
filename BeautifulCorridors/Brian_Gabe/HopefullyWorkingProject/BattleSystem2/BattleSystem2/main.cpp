#include "Charizard.h"
#include "Slowbro.h"
int main()
{
	// need to seed for random
	srand(static_cast<int>(time(NULL)));
	int input = 0;
	int compInput = 0;

	// Test variables
	Charizard* testChar1 = new Charizard();
	Slowbro* testBro1 = new Slowbro();

	/*testBro1->useMove(0, testChar1);
	testChar1->useMove(0, testBro1);
	testBro1->useMove(1, NULL);
	testChar1->useMove(1, testBro1);*/

	

	while (input >= 0 && !testBro1->didFaint() && !testChar1->didFaint())
	{
		system("CLS");
		std::cout << testBro1->getName() << " VS. " << testChar1->getName() << std::endl;

		std::cout << "\nYour move: What should Slowbro do?\n";
		testBro1->displayMoveList();

		std::cin >> input;
		if (input < 0)
			break;
		else if (input >= 0 && input <= 3)
			testBro1->useMove(input, testChar1);

		std::cout << "\nPress ENTER to continue\n";
		std::cin.get();
		std::cin.get();

		if (testChar1->didFaint())
			break;
		compInput = randomNumber(0, 3);
		testChar1->useMove(compInput, testBro1);

		std::cout << "\nPress ENTER to continue\n";
		std::cin.get();

		if (testBro1->didFaint())
			break;
	}


	delete testChar1;
	delete testBro1;

	return 0;
}