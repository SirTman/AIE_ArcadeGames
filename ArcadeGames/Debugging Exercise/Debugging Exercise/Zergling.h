#pragma once

#include "Entity.h"
class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();

	int attack();
	int health;
	void takeDamage(int damage);

};

