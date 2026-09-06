#pragma once
#include <string>

class Player
{
private:
	std::string name;
	int money; 

public:
	Player();

	std::string& getName();

	int getMoney() const;

	void setName(const std::string& newName);



};

