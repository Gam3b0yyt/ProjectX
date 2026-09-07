#include "Player.h"

Player::Player()
{
	name = "Lynx";

	money = 1500;

    characterType = characterTypes::CLERIC;
}

std::string& Player::getName()
{
	return name;
}

int Player::getMoney() const
{
	return money;
}

characterTypes Player::getType()
{
	return characterType;
}

void Player::setName(const std::string& newName)
{
	if (newName != "Lynx") {
		name = newName;
	}
}

void Player::setCharacterType(const characterTypes& newCharacterType)
{
	if (newCharacterType != characterTypes::CLERIC) {
		characterType = newCharacterType;
	}
	
}
