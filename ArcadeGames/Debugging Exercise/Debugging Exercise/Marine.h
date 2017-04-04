#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	Marine();
	~Marine();

	int attack();
	int health;
	void takeDamage(int damage);

};

