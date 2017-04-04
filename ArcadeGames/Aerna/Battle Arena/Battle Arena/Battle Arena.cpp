#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

//Prevents the Random Numbers being the same every time the program is started
void seedRandom() {
	srand(time(NULL));
}

//Enemy Class - Start
class Enemy
{
public:
	Enemy();
	~Enemy();
	void showStats();
	void takedamge(int NUM);
	bool m_alive = false;
	bool m_b_team = false;
	std::string m_name = "";
	void Setname(std::string n);
	int m_attack;
protected:
	int m_health;
	

};

Enemy::Enemy() {
	//set Sats
	m_health = 5 + rand() % 5 + 1;
	m_attack = rand() % 3 + 1;
}

Enemy::~Enemy() {}
void Enemy::Setname(std::string n)
{
	m_name = n;
}

void Enemy::showStats() 
{

	std::cout 
		<< m_name.c_str()
		<< "\nHealth is: " << m_health 
		<< "\nAttack is: " << m_attack << "\n\n";

}

void Enemy::takedamge(int ATKNUM)
{
	m_health -= ATKNUM;
	if (m_health <= 0)
	{
		m_alive = false;
	}
}
//Enemy Class - End

void CallList(Enemy A[], Enemy B[], int NUM)
{
	//Team A
	for (int i = 0; NUM > i; i++)
	{
		if (A[i].m_alive == false)
		{
			continue;
		}
		else
		{
			//std::cout << A[i] << "\n";
			A[i].m_name;
			A[i].showStats();
		}
	}
	std::cout << "\n--------------\n";
	//Team B
	for (int i = 0; NUM > i; i++)
	{
		if (B[i].m_alive == false)
		{
			continue;
		}
		else
		{
			//std::cout << A[i] << "\n";
			B[i].m_name;
			B[i].showStats();
		}
	}
}

int CombatRound(Enemy A[], Enemy B[], int NUMofFighters)
{
	system("cls");
	//Sets total fighters
	int totalfighters = NUMofFighters * 2;
	int DeathCountor = 0;
	//Target and Attack excutor
	for (int i = 0; totalfighters > i; i++)
	{
		//A Turn
		if (A[i].m_alive == true)
		{
			int AAtkTar = rand() % NUMofFighters;
			//Checks if target is alive
			while (B[AAtkTar].m_alive == false)
			{
				//Checks to see if there is a Target to actually attack that isn't dead
				AAtkTar += 1;
				DeathCountor += 1;
				if (DeathCountor >= NUMofFighters)
				{
					break;
				}
				if (AAtkTar <= NUMofFighters)
				{
					AAtkTar = 0;
				}
			}
			//The Attack
			std::cout << A[i].m_name.c_str() << " Attacked " << B[AAtkTar].m_name.c_str() << "\n\n";
			B[AAtkTar].takedamge(A[i].m_attack);
		}

		//B Turn
		if (B[i].m_alive == true)
		{
			int BAtkTar = rand() % NUMofFighters;
			//Checks if target is alive
			while (A[BAtkTar].m_alive == false)
			{
				//Checks to see if there is a Target to actually attack that isn't dead
				BAtkTar += 1;
				DeathCountor += 1;
				if (DeathCountor >= NUMofFighters)
				{
					break;
				}
				if (BAtkTar <= NUMofFighters)
				{
					BAtkTar = 0;
				}
			}
			//The Attack
			std::cout << B[i].m_name.c_str() << " Attacked " << A[BAtkTar].m_name.c_str() << "\n\n";
			A[BAtkTar].takedamge(B[i].m_attack);
		}
	}
		system("pause");
		
	  //Checks if one side is dead
		DeathCountor = 0;
		//A
		for (int i = 0; totalfighters >= i; i++)
		{
			if (DeathCountor == totalfighters)
			{
				system("cls");
				CallList(A, B, NUMofFighters);
				system("pause");
				system("cls");
				std::cout << "B Team Wins\n";
				system("pause");
				return 1;
			}
			if (A[i].m_alive == true)
			{
				DeathCountor = 0;
				break;
			}
			else
			{
				DeathCountor++;
					continue;
			}
		}
		DeathCountor = 0;
		//B
		for (int i = 0; totalfighters >= i; i++)
		{
			if (DeathCountor == totalfighters)
			{
				system("cls");
				CallList(A,B, NUMofFighters);
				system("pause");
				system("cls");
				std::cout << "A Team Wins\n";
				system("pause");
				return 1;
			}
			if (B[i].m_alive == true)
			{
				DeathCountor = 0;
				break;
			}
			else
			{
				DeathCountor++;
				continue;
			}
		}
		return 0;
}


int main()
{
	seedRandom();
	
	int nFighter = 1; //Number of Fighters on each side
	int userInput = 0;
	
	std::string TeamAname;
	std::string TeamBname;
	
	std::cout << "Please enter the name of the first team\n";
	std::cin >> TeamAname;

	std::cout << "\nPlease enter the name of the second team\n";
	std::cin >> TeamAname;

	bool enemiesSet = false;

	do {
		std::cout << "\nPlease enter number of enemies (min. 1, max. 5)\n";
		std::cin >> userInput;
		if (userInput < 1 || userInput > 5) 
		{ 
			std::cout << "Bad input!"; 
		}
		else {
			nFighter = userInput;
			enemiesSet = true;
		}
	} while (!enemiesSet);
	
	Enemy teamA[10];
	Enemy teamB[10];
	std::string NameingAs = "";
	std::string NameingBs = "";
	std::string LetterAssing[10] = {" A"," B"," C" ," D" ," E" ," F" ," G" ," H" ," I" ," J"};

	//Make Fighters
	for (int i = 0; i < nFighter; i++)
	{
		//Team A
		NameingAs = TeamAname + LetterAssing[i];
		teamA[i].Setname(NameingAs);
		teamA[i].m_alive = true;

		//Team B
		NameingAs = TeamBname + LetterAssing[i];
		teamB[i].Setname(NameingAs);
		teamB[i].m_alive = true;
		teamB[i].m_b_team = true;
	}

	//The actual fight
	bool BattleRunning = true;
	while (BattleRunning)
	{
		system("cls");
		//List Fighters
		CallList(teamA, teamB, nFighter);
		system("pause");
		int HasaSideWon = CombatRound(teamA, teamB, nFighter);
		//If there is no one left to fight then that team wins
		if (HasaSideWon == 1)
		{
			BattleRunning = false;
			break;
		}
		else
		{
			continue;
		}
	}
	return 0;
}