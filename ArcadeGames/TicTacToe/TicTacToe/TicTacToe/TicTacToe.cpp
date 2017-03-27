// TicTacToe.cpp : Defines the entry point for the console application.
//

#include <iostream>

//Tic tack toe
struct GameMarks
{
	char XorO = '-';
	bool taken = false;

};
int CheckWinConditions(GameMarks SymbolsInPlay[])
{
	// 0 = Nothing, 1 = Win, 2 = Draw
	int Numberofsomekind = 0;
	int Num = 0;
	//Horisontal
	for (int i = 1; Num <= 3; i++)
	{
		Num = (3 * (i - 1));
		if (SymbolsInPlay[1 + Num].XorO != '-' && SymbolsInPlay[1 + Num].XorO == SymbolsInPlay[2 + Num].XorO && SymbolsInPlay[1 + Num].XorO == SymbolsInPlay[3 + Num].XorO && SymbolsInPlay[2 + Num].XorO == SymbolsInPlay[3 + Num].XorO)
		{
			return 1;
		}
	}

	//Vertical
	Num = 0;
	for (int i = 0; Num <= 2; i++)
	{
		Num += i;
		if (SymbolsInPlay[1 + Num].XorO != '-' && SymbolsInPlay[1 + Num].XorO == SymbolsInPlay[4 + Num].XorO && SymbolsInPlay[1 + Num].XorO == SymbolsInPlay[7 + Num].XorO && SymbolsInPlay[4 + Num].XorO == SymbolsInPlay[7 + Num].XorO)
		{
			return 1;
		}
	}

	//Diagonal
	//5 is the center

	//159
	if (SymbolsInPlay[5].XorO != '-' && SymbolsInPlay[1].XorO == SymbolsInPlay[5].XorO && SymbolsInPlay[5].XorO == SymbolsInPlay[9].XorO && SymbolsInPlay[9].XorO == SymbolsInPlay[1].XorO)
	{
		return 1;
	}

	//753
	if (SymbolsInPlay[5].XorO != '-' && SymbolsInPlay[7].XorO == SymbolsInPlay[5].XorO && SymbolsInPlay[5].XorO == SymbolsInPlay[3].XorO && SymbolsInPlay[3].XorO == SymbolsInPlay[7].XorO)
	{
		return 1;
	}

	//Check for Draw
	for (int i = 0; Num <= 2; i++)
	{
		Num += i;
		if (SymbolsInPlay[Num].XorO == false)
		{
			break;
		}
		else if (Num == 9)
		{
			return 2;
		}
	}

	return 0;
}



int main()
{
	//Tic tack toe
	bool TicTacToe = true;
	bool XTurn = true;
	GameMarks SymbolsInPlay[10];

	while (TicTacToe)
	{

		std::cout << " 1 2 3\n";
		std::cout << "1" << SymbolsInPlay[1].XorO << "|" << SymbolsInPlay[2].XorO << "|" << SymbolsInPlay[3].XorO << "\n -+-+-\n";
		std::cout << "2" << SymbolsInPlay[4].XorO << "|" << SymbolsInPlay[5].XorO << "|" << SymbolsInPlay[6].XorO << "\n -+-+-\n";
		std::cout << "3" << SymbolsInPlay[7].XorO << "|" << SymbolsInPlay[8].XorO << "|" << SymbolsInPlay[9].XorO << "\n";


		int Row = 0;
		int CollomSelector = 0;
		int Collom = 0;
		//Who's Turn
		if (XTurn)
		{
			std::cout << "X's Turn\n";
		}
		else
		{
			std::cout << "O's Turn\n";
		}
		//Collom
		std::cout << "Chosse a Collum (V)\n";
		std::cin >> Collom;
		//Row
		std::cout << "Chosse a Row    (>)\n";
		std::cin >> Row;

		//Position Calculator
		int Num = Collom + (3 * (Row - 1));

		//std::cout << Num;
		//system("pause");
		if (SymbolsInPlay[Num].taken == false && Num <= 9 && Num >= 1)
		{
			if (XTurn)
			{
				SymbolsInPlay[Num].XorO = 'X';
				SymbolsInPlay[Num].taken = true;
				XTurn = false;
			}
			else
			{
				SymbolsInPlay[Num].XorO = 'O';
				SymbolsInPlay[Num].taken = true;
				XTurn = true;
			}
		}

		//Check if the Game is over
		//Win
		//CheckWinConditions(SymbolsInPlay);
		int Outcome = CheckWinConditions(SymbolsInPlay);
		if (Outcome == 1)
		{
			//Win Screen
			system("cls");
			std::cout << "Won\n";
			std::cout << SymbolsInPlay[1].XorO << "|" << SymbolsInPlay[2].XorO << "|" << SymbolsInPlay[3].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[4].XorO << "|" << SymbolsInPlay[5].XorO << "|" << SymbolsInPlay[6].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[7].XorO << "|" << SymbolsInPlay[8].XorO << "|" << SymbolsInPlay[9].XorO << "\n";
			break;
		}

		//Draw
		if (Outcome == 2)
		{
			//Draw Screen
			system("cls");
			std::cout << "Draw\n";
			std::cout << SymbolsInPlay[1].XorO << "|" << SymbolsInPlay[2].XorO << "|" << SymbolsInPlay[3].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[4].XorO << "|" << SymbolsInPlay[5].XorO << "|" << SymbolsInPlay[6].XorO << "\n-+-+-\n";
			std::cout << SymbolsInPlay[7].XorO << "|" << SymbolsInPlay[8].XorO << "|" << SymbolsInPlay[9].XorO << "\n";
			break;
		}
		system("cls");
	}

	system("pause");
	return 0;
}

