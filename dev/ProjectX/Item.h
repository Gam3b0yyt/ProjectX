#pragma once
#include <string>

enum class ItemType
{
	CONSUMABLE,
	WEAPON,
	ARMOR
};

struct Item
{
	std::string name;
	ItemType type;
	int price;
	int healthRestore = 0;
	int manaRestore = 0;
	int attackBonus = 0;
	int defenseBonus = 0;
};
