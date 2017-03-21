// ArcadeGames.cpp : Defines the entry point for the console application.
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


//Tic tack toe
struct GameMarks
{
	char XorO = '-';
	bool taken = false;

};
int CheckWinConditions(GameMarks SymbolsInPlay[])
{
	if (SymbolsInPlay[1].XorO == SymbolsInPlay[2].XorO && SymbolsInPlay[1].XorO == SymbolsInPlay[3].XorO && SymbolsInPlay[2].XorO == SymbolsInPlay[3].XorO)
	{

	}
	if (SymbolsInPlay[4].XorO == SymbolsInPlay[5].XorO && SymbolsInPlay[4].XorO == SymbolsInPlay[6].XorO && SymbolsInPlay[5].XorO == SymbolsInPlay[6].XorO)
	{

	}
	return 0;
}


int main()
{
	int gameselection = 1;
	//Number Guessing game
	if (gameselection == 1)
	{
		//Number Guessing game
		bool NumGuessingGame = true;
		srand (time(NULL));
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
	}
	//Tic tack toe
	else if (gameselection == 2)
	{
		//Tic tack toe
		bool TicTacToe = false;
		bool XTurn = true;
		GameMarks SymbolsInPlay[9];

		while (TicTacToe)
		{
			std::cout << SymbolsInPlay[1].XorO << "|" << SymbolsInPlay[2].XorO << "|" << SymbolsInPlay[3].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[4].XorO << "|" << SymbolsInPlay[5].XorO << "|" << SymbolsInPlay[6].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[7].XorO << "|" << SymbolsInPlay[8].XorO << "|" << SymbolsInPlay[9].XorO << "\n";

			int Num = 0;
			int Row = 0;
			int Collom = 0;
			std::cin >> Num;
			if (XTurn)
			{
				SymbolsInPlay[Num].XorO = 'X';
				SymbolsInPlay[Num].taken = true;
			}
			else
			{
				SymbolsInPlay[Num].XorO = 'O';
				SymbolsInPlay[Num].taken = true;
			}

			system("cls");
		}
	}
	//Battle Arena
	else if (gameselection == 3)
	{

	}

	system("pause");
	return 0;
}

