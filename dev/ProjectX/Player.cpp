#include "Player.h"

Player::Player()
{
	name = "Lynx";

	money = 1500;
}

std::string& Player::getName()
{
	return name;
}

int Player::getMoney() const
{
	return money;
}

void Player::setName(const std::string& newName)
{
	if (newName != "Lynx") {
		name = newName;
	}
}
