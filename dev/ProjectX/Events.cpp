#include "Events.h"

void Events::Intro()
{
	ui.messageBox("Long ago... In a world like no other...");
	ui.messageBox("There were two brothers who lived in harmony");
	ui.messageBox("But when their father died, everything changed");
	ui.messageBox("The older brother Onyx, got jealous that his younger brother would get the throne.");
	ui.messageBox("Full of rage the older brother stabbed his brother in back...");
	ui.messageBox("He launched him out of the kingdom, and thought he would never see him again");
	ui.messageBox("The younger brother landed somewhere in the forest...");
	ui.messageBox("Luckily someone found him and healed his wounds");
	ui.messageBox("Suddenly the younger Brother woke up...");

}

void Events::Title()
{
	ui.clearScreenForGame();
	std::cout << "====================================\n";
	std::cout << "          PROJECT X: RPG             \n";
	std::cout << "           by: Jose Ruiz             \n";
	std::cout << "====================================\n\n";
	ui.pause();
}

void Events::settings() 
{
	std::cout << "Settings: \n";

	
}

void Events::mainMenu()
{
	std::vector<std::string> mainMenuChoices = {
		"New Game", "Load Game", "Settings", "Exit"
	};

	int choice = 0;

	do {
		choice = ui.DisplayMenuAndPromptUser("Main Menu: ", mainMenuChoices);

		switch (choice) {
		case 1: // Starts a new Game
			newGame();
			break;
		case 2: // Loads the save file 
			break;
		case 3: // Goes to the settings Menu
			settings();
			break;
		case 4: // Will exit the program
			break;
		default:
			break;
		}

	} while (choice != 4);


}

void Events::CreatePlayer()
{
	std::string name;
	
	ui.messageBox("Hello there, You took quite a fall");
	ui.messageBox("Tell me, what's your name?");
	ui.clearScreenForGame();
	do
	{
		std::cout << "Enter Your Name: \n" << std::endl;
		std::getline(std::cin, name);
		if (name == "")
		{
			name = "Lynx";
		}

	} while (name.empty());
	player.setName(name);
	ui.messageBox(name);
	ui.messageBox("That's quite a name");
	

	ui.messageBox("You look quite powerful now tell me");
	
	std::vector<std::string> classes = { "Knight", "Sorcerer", "Barbarian", "Monk", "Fighter", "Cleric" };

	int choice = ui.DisplayMenuAndPromptUser("What type of hero are you?", classes);
	player.setCharacterType(static_cast<characterTypes>(choice - 1));
	
	switch(player.getType())
	{
    case characterTypes::KNIGHT:
		player.setMaxHealth(130); player.setHealth(130); player.setAttack(16); player.setDefense(9); player.setMaxMana(25); player.setMana(25); break;
	case characterTypes::SORCERER:
		player.setMaxHealth(80); player.setHealth(80); player.setAttack(12); player.setDefense(3); player.setMaxMana(100); player.setMana(100); break;
	case characterTypes::BARBARIAN:
		player.setMaxHealth(150); player.setHealth(150); player.setAttack(20); player.setDefense(4); player.setMaxMana(20); player.setMana(20); break;
	case characterTypes::MONK:
		player.setMaxHealth(105); player.setHealth(105); player.setAttack(17); player.setDefense(6); player.setMaxMana(45); player.setMana(45); break;
	case characterTypes::FIGHTER:
		player.setMaxHealth(115); player.setHealth(115); player.setAttack(18); player.setDefense(7); player.setMaxMana(30); player.setMana(30); break;
	case characterTypes::CLERIC:
		player.setMaxHealth(95); player.setHealth(95); player.setAttack(13); player.setDefense(5); player.setMaxMana(75); player.setMana(75); break;
	}

	ui.messageBox("Ah I see...");
	ui.messageBox("Listen there's no time your brother is out of control");
	ui.messageBox(player.getName());
	ui.messageBox("You are the only hope for this world...");
	ui.messageBox("Save it please...");
	ui.messageBox("Your adventure begins...");




	

}

void Events::newGame()
{
	player = Player();
	storyProgress = 0;
	CreatePlayer();
	gameMenu();

}

void Events::gameMenu()
{
	bool inGame = true;
	std::vector<std::string> choices = { "Explore", "Shop", "Save Game", "Status", "Return to Main Menu" };

	while (inGame) 
	{
		ui.clearScreenForGame();
		std::cout << "===== WORLD =====\n";
		std::cout << "Hero: " << player.getName() << "  Lv. " << player.getLevel() << "\n";
		std::cout << "HP: " << player.getHealth();
		std::cout << "   MP: " << player.getMana() << "\n";

		int choice = ui.DisplayMenuAndPromptUserWithoutClearing("What will you do?", choices);
		switch (choice)
		{
		case 1: // Explore
			finalBossCheck();
			break;
		case 2: // Shop

			break;
		case 3: // Save game (FOR LATER)

			break;
		case 4: // Stats
			showStats();
			break;
		case 5: // Go back to main menu
			inGame = false;
			break;

		default:
			break;

		}
	}
}

void Events::showStats()
{
	ui.clearScreenForGame();
	std::cout << "===== CHARACTER STATS =====\n\n";
	std::cout << "Name: " << player.getName() << "\n";
	std::cout << "Level: " << player.getLevel() << "\n";
	std::cout << "EXP: " << player.getExperience() << "" << player.getLevel() * 100 << "\n";
	std::cout << "HP: " << player.getHealth() << "\n";
	std::cout << "MP: " << player.getMana() << "\n";
	std::cout << "Attack: " << player.getAttack() << "\n";
	std::cout << "Defense: " << player.getDefense() << "\n";
	std::cout << "Gold: " << player.getMoney() << "\n\n";
	ui.pause();
}

void Events::finalBossCheck()
{
	if (storyProgress == 10 && player.getMorale() == 100)
	{
		//starts the true final boss and will trigger the true ending
	}
	else if (storyProgress == 10)
	{
		//starts final boss and will trigger either ending
	}
	else
	{
		explore();
	}
	


}

void Events::explore()
{
	ui.messageBox("You travel deeper into the unknown...");
	int eventRoll = std::rand() % 100;
	if (eventRoll < 60)
	{
		// This will trigger an enemy and start to fight
		Monster monster = createRandomMonster();
		battle(monster);
	}
	else if (eventRoll < 85)
	{
		switch (std::rand() % 4)
		{
		case 0:
		{
			ui.messageBox("An old Lady appears out of nowhere...");
			ui.messageBox("She ask if you could help her with some groceries");

			std::vector<std::string> yesOrNo = { "Yes", "No", };
			int choice = 0;
			choice = ui.DisplayMenuAndPromptUser("Will you help the lady?", yesOrNo);
			if (choice == 1)
			{
				ui.messageBox("You decide to help the Old Lady");
				ui.messageBox("She's grateful for your help and gives you something");

				int gold = player.getMoney() + std::rand() % 1000;
				player.setMoney(gold);
				player.setMorale(20);
				storyProgress++;

				ui.messageBox("She gave you some gold... How nice");
			}
			else
			{
				//batlle dragon
			}
			break;
		}

		case 1:

		case 2:

		case 3:

		case 4:
			break;
		}

	}
}

Monster Events::createRandomMonster() const
{
	switch (std::rand() % 5)
	{
	case 0: return Monster("Forest Slime", monsterType::BEAST, 45, 9, 2, 30);
	case 1: return Monster("Goblin", monsterType::BEAST, 60, 12, 4, 40);
	case 2: return Monster("Dark Plant", monsterType::PLANT, 70, 13, 5, 50);
	case 3: return Monster("Fire Elemental", monsterType::ELEMENTAL, 85, 16, 6, 65);
	default: return Monster("Fallen Celestial", monsterType::CELESTIAL, 100, 18, 8, 80);
	}
}

void Events::battle(Monster enemy)
{
	while (player.isAlive() && enemy.isAlive())
	{
		ui.clearScreenForGame();
		std::cout << "====================================\n";
		std::cout << "              BATTLE                 \n";
		std::cout << "====================================\n\n";
		std::cout << player.getName() << " HP " << player.getHealth() << "/" << player.getMaxHealth()
			<< "  MP " << player.getMana() << "/" << player.getMaxMana() << "\n";
		std::cout << enemy.getName() << " HP " << enemy.getHealth() << "/" << enemy.getMaxHealth() << "\n\n";

		playersTurn(enemy);

		if (enemy.isAlive()) monsterTurn(enemy);

		if (player.isAlive())
		{
			int reward = enemy.getExperienceReward();
			player.setExperience(player.getExperience() + reward);
			player.setMoney(player.getMoney() + reward);
			std::cout << "\nYou defeated " << enemy.getName() << "!\n";
			std::cout << "EXP +" << reward << "   Gold +" << reward << "\n";
			++storyProgress;

			while (player.getExperience() >= player.getLevel() * 100)
			{
				if (player.levelUP())
					std::cout << "LEVEL UP! You are now level " << player.getLevel() << "!\n";
			}
			ui.pause();
		}
		else
		{
			std::cout << "\nYou were defeated...\n";
			player.fullRestore();
			std::cout << "You awaken at the last safe area.\n";
			ui.pause();
		}
	
	}
}

void Events::playersTurn(Monster& enemy)
{
	std::vector<std::string> actions = { "Attack", "Power Strike (15 MP)", "Heal", "Use Health Potion", "Use Mana Potion" };
	int choice = ui.DisplayMenuAndPromptUserWithoutClearing("What will you do?", actions);

	int damage = 0;
	int crit = 1;
	int critPercent = (std::rand() % 100) ;

	if (critPercent == 20) {
		crit = 2;
	}

	switch (choice)
	{
	case 1:
		damage = ((player.getAttack() * crit) - enemy.getDefense());
		enemy.takeDamage(damage);
		std::cout << "You attack for " << damage << " damage!\n";
		break;
	case 2:
		if (player.spendMana(15))
		{
			damage = ((player.getAttack() * (crit * crit)) - enemy.getDefense());
			enemy.takeDamage(damage);
			std::cout << "Power Strike deals " << damage << " damage!\n";
		}
		else
			std::cout << "Not enough MP!\n";
		break;
	case 3:
		if (player.spendMana(10))
		{
			player.heal(30);
			std::cout << "You restore 30 HP.\n";
		}
		else
			std::cout << "Not enough MP!\n";
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
	ui.pause();
}

void Events::monsterTurn(Monster& enemy)
{
	int crit = 1;
	int critPercent = (std::rand() % 100);

	if (critPercent == 20) {
		crit = 2;
	}
	int damage = ((player.getAttack() * crit) - enemy.getDefense());
	player.setHealth(player.getHealth() - damage);
	std::cout << enemy.getName() << " attacks you for " << damage << " damage!\n";
	ui.pause();
}