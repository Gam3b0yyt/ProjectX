#pragma once
#include <string>
#include "characterTypes.h"

class Player
{
private:
	std::string name;
	int money; 
	characterTypes characterType;

public:
	Player();

	std::string& getName();

	int getMoney() const;

	characterTypes getType();

	void setName(const std::string& newName);

	void setCharacterType(const characterTypes& newType);

	


};

