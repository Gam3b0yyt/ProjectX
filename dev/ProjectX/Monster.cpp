#include "Monster.h"

Monster::Monster()
{
	name = "";
	type = monsterType::NONE;
	health = -1;
}

std::string Monster::getName() const
{
	return name;
}

monsterType Monster::getType() const
{
	return type;
}

int Monster::getHealth() const
{
	return health;
}
