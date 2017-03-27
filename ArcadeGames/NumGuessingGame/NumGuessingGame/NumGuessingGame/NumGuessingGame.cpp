// NumGuessingGame.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <time.h>


//Number Guessing game
int NumberChecker(int TheNum, int TheGuess)
{
	if (TheNum == TheGuess)
	{
		std::cout << "\ncongrats you guessed the number it was\n " << TheGuess;
		return true;
	}
	if (TheGuess < TheNum)
	{
		std::cout << "\nHigher\n";
		return false;
	}
	if (TheGuess > TheNum)
	{
		std::cout << "\nLower\n";
		return false;
	}
}


int main()
{
		//Number Guessing game
		bool NumGuessingGame = true;
		srand(time(NULL));
		int NumToGuess = rand() % 100 + 1;
		int NumGuess = 0;
		//std::cout << "DEBUG:" << NumToGuess << "\n";
		std::cout << "I'm thinking between 0 & 100" << "\n";
		while (NumGuessingGame)
		{
			std::cin >> NumGuess;
			system("cls");
			std::cout << NumGuess;
			if (NumberChecker(NumToGuess, NumGuess) == true)
			{
				//std::getchar();
				NumGuessingGame = true;
				break;
			}
			else
			{
				//std::getchar();
			}

		}
		system("pause");
		return 0;
}

