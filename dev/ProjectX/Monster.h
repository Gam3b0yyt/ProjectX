#pragma once
#include <string>
#include "monsterTypes.h"
class Monster
{
private:
	std::string name;
	monsterType type;
	int health;

public:
	Monster();

	std::string getName() const;

	monsterType getType() const;

	int getHealth() const;




};

