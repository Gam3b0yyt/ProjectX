#include "Shop.h"

const std::vector<Item> Shop::stock = {
	{ "Health Potion", ItemType::CONSUMABLE, std::rand() % 1000, 40, 0, 0, 0},
	{ "Mana Potion",   ItemType::CONSUMABLE, std::rand() % 1000, 0, 30, 0, 0},
	{ "Iron Sword",    ItemType::WEAPON,    std::rand() % 1000, 0, 0, 5, 0 },
	{ "Leather Armor", ItemType::ARMOR,     std::rand() % 1000, 0, 0, 0, 5}
};

void Shop::open()
{
	bool shopping = true;
	while (shopping)
	{
		std::vector<std::string> options;
		for (const auto& item : stock)
			options.push_back(item.name + " - " + std::to_string(item.price) + " gold");
		options.push_back("Leave");

		int choice = ui.DisplayMenuAndPromptUser("Welcome! What would you like to buy?", options);

		if (choice == static_cast<int>(stock.size()) + 1) { shopping = false; break; }

		const Item& chosen = stock[choice - 1];
		if (player.getMoney() >= chosen.price)
		{
			player.setMoney(player.getMoney() - chosen.price);
			player.addItem(chosen);
			ui.messageBox("Bought " + chosen.name + "!", 5);
		}
		else
		{
			ui.messageBox("You don't have enough gold.", 5);
		}
	}
}
