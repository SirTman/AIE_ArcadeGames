// Battle Arena.cpp : Defines the entry point for the console application.
//
/*
#include <iostream>
#include "Fighter.h"
#include <cstdlib>
#include <time.h>
#include <string>


int main()
{
	srand(time(NULL));

	std::cout << "Welcome\n";
	std::cout << "To fight club\n\n";
	std::cout << "Welcome\n";
	std::string name = "Hey";
	return 0;
}
*/

#include <iostream>
#include <cstdlib>
#include <time.h>


//Prevents the Random Numbers being the same every time the program is started
void seedRandom() {
	srand(time(NULL));
}

//Enemy Class - Start
class Enemy
{
public:
	Enemy(std::string n);
	~Enemy();
	void showStats();
protected:
	int m_health;
	int m_attack;
	int m_damage;
	bool m_alive = true;
	bool m_team = false;
	std::string m_name;
};

Enemy::Enemy(std::string n) {
	m_health = rand() % 10 + 1;
	m_damage = rand() % 3 + 1;
	m_name = n;
}

Enemy::~Enemy() {}

void Enemy::showStats() {
	std::cout << "Health is: " << m_health;
	std::cout << "\nAttack is: " << m_attack;
	std::cout << "\nDamage is: " << m_damage;

}
//Enemy Class - End

int main()
{
	seedRandom();
	
	int nFighter; //Number of Fighters on each side
	int userInput = 0;


	bool enemiesSet = false;
	do {
		std::cout << "\n" << "Please enter number of enemies (min. 1, max. 10)";
		std::cin >> userInput;
		if (userInput < 1 || userInput > 10) 
		{ 
			std::cout << "Bad input!"; 
		}
		else {
			nFighter = userInput;
			enemiesSet = true;
		}
	} while (!enemiesSet);
	
	//Make Fighters
	const std::string enemyName[] = { "Fighter" };
}