#pragma once
#include "Player.h"
#include "UI.h"
#include <vector>

class Shop
{
public:
	Shop(Player& player, UI& ui) : player(player), ui(ui) {}
	void open();

private:
	Player& player;
	UI& ui;
	static const std::vector<Item> stock;
};

