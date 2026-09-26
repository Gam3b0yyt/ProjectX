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
		if (player.getMoney() < chosen.price)
		{
			ui.messageBox("You don't have enough gold.", 15);
			continue;
		}

		player.setMoney(player.getMoney() - chosen.price);

		if (chosen.type == ItemType::WEAPON)
		{
			player.setAttack(player.getAttack() + chosen.attackBonus);
			ui.messageBox("You equip the " + chosen.name + " right away. Attack is now " + std::to_string(player.getAttack()) + ".", 15);
		}
		else if (chosen.type == ItemType::ARMOR)
		{
			player.setDefense(player.getDefense() + chosen.defenseBonus);
			ui.messageBox("You equip the " + chosen.name + " right away. Defense is now " + std::to_string(player.getDefense()) + ".", 15);
		}
		else // CONSUMABLE
		{
			player.addItem(chosen);
			ui.messageBox("Bought " + chosen.name + "!", 5);

			std::vector<std::string> useNow = { "Use it now", "Save it for later" };
			int useChoice = ui.DisplayMenuAndPromptUser("Use it right away?", useNow);
			if (useChoice == 1)
			{
				if (chosen.healthRestore > 0)
				{
					player.heal(chosen.healthRestore);
					ui.messageBox("You restore " + std::to_string(chosen.healthRestore) + " HP.", 15);
				}
				if (chosen.manaRestore > 0)
				{
					player.setMana(std::min(player.getMaxMana(), player.getMana() + chosen.manaRestore));
					ui.messageBox("You restore " + std::to_string(chosen.manaRestore) + " MP.", 15);
				}
				player.removeItem(chosen.name, 1);
			}
		}
	}
}
