#include "Events.h"


void Events::Intro()
{
	ui.messageBox("|| Long ago... In a world like no other... ||", 20);
	ui.messageBox("|| There were two brothers who lived in harmony ||", 20);
	ui.messageBox("|| But when their father died, everything changed ||", 20);
	ui.messageBox("|| The older brother Onyx, got jealous that his younger brother would get the throne.||", 20);
	ui.messageBox("|| Full of rage the older brother stabbed his brother in back... ||", 20);
	ui.messageBox("|| He launched him out of the kingdom, and thought he would never see him again ||", 20);
	ui.messageBox("|| The younger brother landed somewhere in the forest... ||", 20);
	ui.messageBox("|| Luckily someone found him and healed his wounds ||", 20);
	ui.messageBox("|| Suddenly the younger Brother woke up... ||", 20);

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


void Events::mainMenu()
{
	std::vector<std::string> mainMenuChoices = {
		"New Game", "Load Game", "Credits", "Exit"
	};

	int choice = 0;

	do {
		choice = ui.DisplayMenuAndPromptUser("Main Menu: ", mainMenuChoices);

		switch (choice) {
		case 1: // Starts a new Game
			newGame();
			break;
		case 2: // Loads the save file 
			loadGame();
			break;
		case 3: // Goes to the settings Menu
			credits();
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
	
	ui.messageBoxWithCharacterName("Stranger","Hello there, You took quite a fall", 10);
	ui.messageBoxWithCharacterName("Stranger", "Tell me, what's your name?", 10);
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
	ui.messageBoxWithCharacterName("Stranger", name , 10);
	ui.messageBoxWithCharacterName("Stranger", "That's quite a name", 10);
	

	ui.messageBoxWithCharacterName("Stranger", "You look quite powerful now tell me", 10);
	
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

	ui.messageBoxWithCharacterName("Stranger", "Ah I see...", 10);
	ui.messageBoxWithCharacterName("Stranger", "Listen there's no time your brother is out of control", 5);
	ui.messageBoxWithCharacterName("Stranger", player.getName(), 10);
	ui.messageBoxWithCharacterName("Stranger", "You are the only hope for this world...", 10);
	ui.messageBoxWithCharacterName("Stranger", "Save it please...", 10);
	ui.messageBoxWithCharacterName("Stranger", "Your adventure begins...", 10);




	

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
		{
			finalBossCheck();
			break;
		}
		case 2: // Shop
		{
			Shop shop(player, ui);
			shop.open();

			break;
		}
		case 3: // Save game (FOR LATER)
		{
			ui.messageBox("You feel...", 25);
			ui.messageBox("something...", 25);
			ui.messageBox("You're filled with determination.", 25);
			std::vector<std::string> yesOrNo = { "Save", "Don't Save" };
			int option = ui.DisplayMenuAndPromptUser("Would You Like to save?", yesOrNo);
			switch (option)
			{
			case 1: 
			{
				player.fullRestore();
				saveGame();
				break;
			}
			case 2:
			{
				break;
			}
			}
			break;
		}
		case 4: // Stats
		{
			showStats();
			break;
		}
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
	std::cout << "EXP: " << player.getExperience() << " / " << player.getLevel() * 100 << "\n";
	std::cout << "HP: " << player.getHealth() << "/" << player.getMaxHealth() << "\n";
	std::cout << "MP: " << player.getMana() << "/" << player.getMaxMana() << "\n";
	std::cout << "Attack: " << player.getAttack() << "\n";
	std::cout << "Defense: " << player.getDefense() << "\n";
	std::cout << "Gold: " << player.getMoney() << "\n\n";
	ui.pause();
}

void Events::finalBossCheck()
{
	if (storyProgress >= 10 && player.getMorale() >= 100)
	{
		// This will trigger final boss and will activate the true ending if user fights right.
		ui.messageBox("||You feel something within you...||", 25);
		ui.messageBox("||You feel like you can finally face your Brother||", 25);
		std::vector<std::string> yesOrNo = { "yes", "no" };
		int choice = ui.DisplayMenuAndPromptUser("Are you ready?", yesOrNo);
		switch (choice) 
		{
		case 1: 
		{
			ui.messageBox("||You Start Heading towards the castle...||", 20);
			ui.messageBox("||Once you enter...||", 35);
			ui.messageBox("||You are going to face your brother head on||", 25);
			finalBoss();

			//Method to start the boss battle will go here

		 break;
		}
		case 2: 
			ui.messageBox("|| You're right... ||", 15);
			ui.messageBox("|| Maybe we should explore some more...|| ", 15);
			explore();
		}
	}
	else if (storyProgress == 10)
	{
		//starts final boss and will trigger either ending
		ui.messageBox("||You feel something within you...||", 25);
		ui.messageBox("||You feel like you can finally face your Brother||", 25);
		std::vector<std::string> yesOrNo = { "yes", "no" };
		int choice = ui.DisplayMenuAndPromptUser("Are you ready?", yesOrNo);
		switch (choice)
		{
		case 1:
		{
			ui.messageBox("||You Start Heading towards the castle...||", 20);
			ui.messageBox("||Once you enter...||", 35);
			ui.messageBox("||You are going to face your brother head on||", 25);
			finalBoss();

			//Method to start the boss battle will go here

			break;
		}
		case 2:
			ui.messageBox("|| You're right... ||", 15);
			ui.messageBox("|| Maybe we should explore some more...|| ", 15);
			explore();
		}
	}
	else
	{
		explore();
	}
	


}

void Events::explore()
{
	ui.messageBox("|| You travel deeper into the unknown... ||", 15);
	int eventRoll = std::rand() % 100;
	if (eventRoll < 75)
	{
		// This will trigger an enemy and start to fight
		Monster monster = createRandomMonster();
		battle(monster);
	}
	else 
	{
	
		StoryEvents();

	}
}

Monster Events::createRandomMonster() const
{
	struct MonsterTemplate
	{
		std::string name;
		monsterType type;
		int hp, atk, def, exp;
	};

	int lvl = player.getLevel();

	// Levels 1-5
	static const std::vector<MonsterTemplate> tier1 = {
		{ "Forest Slime", monsterType::BEAST,     45, 9,  2, 30 },
		{ "Goblin",        monsterType::BEAST,     60, 12, 4, 40 },
		{ "Dark Plant",    monsterType::PLANT,     70, 13, 5, 50 },
		{ "Fire Sprite",   monsterType::ELEMENTAL, 55, 11, 3, 35 }
	};

	// Levels 6-10
	static const std::vector<MonsterTemplate> tier2 = {
		{ "Dire Wolf",       monsterType::BEAST,     95,  15, 6, 55 },
		{ "Bog Horror",      monsterType::PLANT,     110, 17, 7, 65 },
		{ "Fire Elemental",  monsterType::ELEMENTAL, 120, 19, 8, 75 },
		{ "Restless Spirit", monsterType::UDEAD,     100, 16, 5, 60 }
	};

	// Levels 11-15
	static const std::vector<MonsterTemplate> tier3 = {
		{ "Stone Golem",       monsterType::ELEMENTAL, 160, 22, 14, 110 },
		{ "Thornback Treant",  monsterType::PLANT,     150, 20, 12, 100 },
		{ "Vampire Bat Swarm", monsterType::UDEAD,     140, 24, 10, 105 },
		{ "Fallen Celestial",  monsterType::CELESTIAL, 155, 23, 13, 115 }
	};

	// Levels 16-20
	static const std::vector<MonsterTemplate> tier4 = {
		{ "Young Dragon",    monsterType::DRAGON,    220, 30, 18, 160 },
		{ "Ancient Lich",    monsterType::UDEAD,     200, 28, 16, 150 },
		{ "Storm Elemental", monsterType::ELEMENTAL, 210, 29, 17, 155 },
		{ "Seraph Guardian", monsterType::CELESTIAL, 215, 29, 19, 165 }
	};

	std::vector<MonsterTemplate> pool;

	if (lvl >= 1 && lvl <= 5)
	{
		pool = tier1;
	}
	else if (lvl >= 6 && lvl <= 10)
	{
		pool = tier2;
	}
	else if (lvl >= 11 && lvl <= 15)
	{
		pool = tier3;
	}
	else if (lvl >= 16 && lvl <= 20)
	{
		pool = tier4;
	}
	else // level 21+: every monster you've unlocked so far is in play
	{
		pool.insert(pool.end(), tier1.begin(), tier1.end());
		pool.insert(pool.end(), tier2.begin(), tier2.end());
		pool.insert(pool.end(), tier3.begin(), tier3.end());
		pool.insert(pool.end(), tier4.begin(), tier4.end());
	}

	const MonsterTemplate& t = pool[std::rand() % pool.size()];

	int levelBonus = lvl - 1; // one continuous growth curve, so no tier ever "resets"

	int hp = t.hp + levelBonus * 15;
	int attack = t.atk + levelBonus * 3;
	int defense = t.def + levelBonus * 2;
	int exp = t.exp + levelBonus * 10;

	return Monster(t.name, t.type, hp, attack, defense, exp);
}

void Events::battle(Monster enemy)
{
	while (player.isAlive() == true && enemy.isAlive() == true)
	{
		ui.clearScreenForGame();
		std::cout << "====================================\n";
		std::cout << "              BATTLE                 \n";
		std::cout << "====================================\n\n";
		std::cout << player.getName() << " HP " << player.getHealth() << "/" << player.getMaxHealth()
			<< "  MP " << player.getMana() << "/" << player.getMaxMana() << "\n";
		std::cout << enemy.getName() << " HP " << enemy.getHealth() << "/" << enemy.getMaxHealth() << "\n\n";

		if (playersTurn(enemy))
		{
			return; // fled — skip rewards/penalties entirely, just leave the fight
		}

		if (enemy.isAlive() == true) monsterTurn(enemy);
	
	}
	
	if (player.isAlive() == true)
	{
		int reward = enemy.getExperienceReward();
		player.setExperience(player.getExperience() + reward);
		player.setMoney(player.getMoney() + reward);
		std::cout << "\nYou defeated " << enemy.getName() << "!\n";
		std::cout << "\n";
		std::cout << "EXP +" << reward << "   Gold +" << reward << "\n";
	

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
		std::cout << "\n";
		std::cout << "You awaken at the last safe area.\n";
		ui.pause();
	}
}

void Events::battleEvent(Monster enemy)
{
	while (player.isAlive() == true && enemy.isAlive() == true)
	{
		ui.clearScreenForGame();
		std::cout << "====================================\n";
		std::cout << "             BOSS BATTLE            \n";
		std::cout << "====================================\n\n";
		std::cout << player.getName() << " HP " << player.getHealth() << "/" << player.getMaxHealth()
			<< "  MP " << player.getMana() << "/" << player.getMaxMana() << "\n";
		std::cout << enemy.getName() << " HP " << enemy.getHealth() << "/" << enemy.getMaxHealth() << "\n\n";

		if (playersTurn(enemy))
		{
			return; // fled — skip rewards/penalties entirely, just leave the fight
		}

		if (enemy.isAlive() == true) monsterTurn(enemy);

		

	}

	
	if (player.isAlive() == true)
	{
		int reward = enemy.getExperienceReward();
		player.setExperience(player.getExperience() + reward);
		player.setMoney(player.getMoney() + reward);
		std::cout << "\nYou defeated " << enemy.getName() << "!\n";
		std::cout << "EXP +" << reward << "   Gold +" << reward << "\n";

		storyProgress += 2;               
	

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
		if (storyProgress != 0)
		{
			storyProgress -= 2;   
		}
		player.fullRestore();
		std::cout << "You awaken at the last safe area.\n";
		ui.pause();
	}

	if (enemy.getName() == "Onyx" && enemy.isAlive() == false && player.getMorale() >= 100 ) 
	{
		trueEnding();
	}
	else if (enemy.getName() == "Onyx" && enemy.isAlive() == false)
	{
		neutralEnding();
	}

	if (enemy.getName() == "Dark Gaia" && enemy.isAlive() == false)
	{
		finalEnding();
	}
}

bool Events::playersTurn(Monster& enemy)
{
	std::vector<std::string> actions = { "Attack", "Power Strike (15 MP)", "Heal (10 MP)", "Check Monster Stats", "Use Item", "Flee"};
	int choice = ui.DisplayMenuAndPromptUserWithoutClearing("What will you do?", actions);

	int damage = 0;
	int crit = 1;
	int critPercent = (std::rand() % 100) ;

	if (critPercent <= 19) { crit = 2;}

	switch (choice)
	{
	case 1:
		damage = std::max(1, (player.getAttack() * crit) - enemy.getDefense());
		enemy.takeDamage(damage);
		ui.clearScreenForGame();
		std::cout << "You attack for " << damage << " damage!\n";
		break;
	case 2:
		ui.clearScreenForGame();
		if (player.spendMana(15))
		{
			damage = std::max(1, (player.getAttack() * 2 * crit) - enemy.getDefense());
			enemy.takeDamage(damage);
			std::cout << "Power Strike deals " << damage << " damage!\n";
		}
		else
			std::cout << "Not enough MP!\n";
		break;
	case 3:
		ui.clearScreenForGame();
		if (player.spendMana(10))
		{
			player.heal(30);
			std::cout << "You restore 30 HP.\n";
		}
		else
			std::cout << "Not enough MP!\n";
		break;
	case 4: 
		showMonsterStats(enemy);
		break;
	case 5: // Use Item
	{
		ui.clearScreenForGame();
		const auto& inv = player.getInventory();

		std::vector<std::string> options;
		for (const auto& slot : inv)
			options.push_back(slot.item.name + " x" + std::to_string(slot.quantity));

		if (options.empty())
		{
			std::cout << "You have no items.\n";
			break;
		}

		int itemChoice = ui.DisplayMenuAndPromptUserWithoutClearing("Use which item?", options);
		const Item& chosen = inv[itemChoice - 1].item;

		if (chosen.healthRestore > 0)
		{
			player.heal(chosen.healthRestore);
			std::cout << "You use " << chosen.name << " and restore " << chosen.healthRestore << " HP.\n";
		}
		if (chosen.manaRestore > 0)
		{
			player.setMana(std::min(player.getMaxMana(), player.getMana() + chosen.manaRestore));
			std::cout << "You use " << chosen.name << " and restore " << chosen.manaRestore << " MP.\n";
		}

		player.removeItem(chosen.name, 1);
		break;
	}
	case 6:
	{
		int escapeChance = std::rand() % 100;
		if (escapeChance <= 19)
		{
			ui.messageBox("You Managed to escape...", 15);
			ui.pause();
			return true;
		}
		else
		{
			ui.messageBox("The enemy is too strong to escape", 15);
			return false;
		}
		break;
	}
	default:
			break;
		}
		ui.pause();
		return false;
	}

void Events::monsterTurn(Monster& enemy)
{
	int crit = 1;
	int critPercent = (std::rand() % 100);

	if (critPercent == 20) {
		crit = 2;
	}
	int damage = std::max(1, (enemy.getAttack() * crit) - player.getDefense());
	player.setHealth(player.getHealth() - damage);
	std::cout << "\n";
	std::cout << enemy.getName() << " attacks you for " << damage << " damage!\n";
	ui.pause();
}

void Events::showMonsterStats(Monster enemy)
{
	ui.clearScreenForGame();
	std::cout << "===== Monster Stats =====\n\n";
	std::cout << "Name: " << enemy.getName() << "\n";
	std::cout << "HP: " << enemy.getHealth() << "/ " << enemy.getMaxHealth() << "\n";
	std::cout << "Attack: " << enemy.getAttack() << "\n";
	std::cout << "Defense: " << enemy.getDefense() << "\n";
}

void Events::StoryEvents()
{
	if (AllStoriesDone)
	{
		ui.messageBox("|| There's Nothing Nearby ||", 15);
		return;
	}

	std::vector<int> available;
	if (!oldLadyCheck) available.push_back(0);
	if (!wolfEvent)    available.push_back(1);
	if (!rootMoss)     available.push_back(2);
	if (!flameCoil)    available.push_back(3);
	if (!ghost)        available.push_back(4);

	int pick = available[std::rand() % available.size()];

	switch (pick)
	{
	case 0:
	{
		ui.messageBox("|| An old Lady appears out of nowhere... ||", 15);
		ui.messageBox("|| She ask if you could help her with some groceries ||", 15);

		std::vector<std::string> yesOrNo = { "Yes", "No", };
		int choice = 0;
		choice = ui.DisplayMenuAndPromptUser("Will you help the lady?", yesOrNo);
		if (choice == 1)
		{
			ui.messageBox("|| You decide to help the Old Lady ||", 15);
			ui.messageBox("|| She's grateful for your help and gives you something ||", 15);

			int gold = player.getMoney() + std::rand() % 1500;
			player.setMoney(gold);
			player.setMorale(20);
			storyProgress = storyProgress + 2;

			ui.messageBox("|| She gave you some gold... How nice ||", 15);
		}
		else
		{
			//batlle dragon
			ui.messageBoxWithCharacterName("Old Lady", "You young fellows are all the same", 45);
			ui.messageBoxWithCharacterName("Old Lady", "I'll show you what happens when you don't help your elderly", 35);
			ui.messageBoxWithCharacterName("Old Lady", "||She began to transform||", 45);
			Monster monster = Monster("Celestial Dragon", monsterType::CELESTIAL, 250, 25, 50, 300);
			battleEvent(monster);
			player.setMorale(-20);
		}
		oldLadyCheck = true;
		break;
	}

	case 1:
	{
		ui.messageBox("|| A wolf thrashes against a hunter's trap, blood matting its fur. ||", 15);
		std::vector<std::string> options = { "Free it", "Walk away", "Finish it for the pelt" };
		int choice = ui.DisplayMenuAndPromptUser("What will you do?", options);

		if (choice == 1)
		{
			ui.messageBox("|| It snaps at your hands in panic, then goes still as the trap releases. ||", 5);
			ui.messageBox("|| It watches you a long moment before vanishing into the trees. ||", 5);
			player.setHealth(std::max(1, player.getHealth() - 10));
			player.setMorale(20);
			player.setDefense(player.getDefense() + 25);
			storyProgress += 2;
			wolfEvent = true;
		}
		else if (choice == 3)
		{
			ui.messageBox("|| You take what the trap already caught for you. ||", 5);
			player.setMoney(player.getMoney() + 80);

			Monster monster = Monster("Enraged Dire Wolf", monsterType::BEAST, 180, 18, 35, 220);
			battleEvent(monster);
			player.setMorale(-20);
			wolfEvent = true;
		}
		else
		{
			ui.messageBox("|| You leave it be. Its whimpering fades behind you. ||", 5);
		}
		break;
	}

	case 2:
	{
		ui.messageBox("|| A figure made of root and moss blocks the path, guarding a blackened grove. ||", 15);
		ui.messageBoxWithCharacterName("Moss Figure", "This land sickens. Aid it, or take what you want and go.", 15);
		std::vector<std::string> options = { "Help cleanse the grove", "Take the treasure by force", "Leave it alone" };
		int choice = ui.DisplayMenuAndPromptUser("What will you do?", options);

		if (choice == 1)
		{
			ui.messageBox("|| You spend the day clearing rot from the roots. The grove brightens.||", 15);
			ui.messageBox("|| You lost a bit of money but gained a little more of strength ||", 15);
			player.setMoney(std::max(0, player.getMoney() - 50));
			player.setAttack(player.getAttack() + 15);
			player.setMorale(20);
			storyProgress += 2;
			rootMoss = true;
		}
		else if (choice == 2)
		{
			ui.messageBox("|| The dryad's bark splits into something far less patient. ||", 15);

			Monster monster = Monster("Blighted Treant", monsterType::PLANT, 260, 26, 48, 280);
			battleEvent(monster);
			player.setMorale(-20);
			rootMoss = true;
		}
		else
		{
			ui.messageBox("|| You step around the grove and keep moving. ||", 15);
		}
		break;
	}

	case 3:
	{
		ui.messageBox("|| Flames coil into a rough humanoid shape atop a scorched shrine. ||", 15);
		ui.messageBoxWithCharacterName("Flame Coil", "Travelers pay tribute here. Or they take what isn't theirs.", 15);
		std::vector<std::string> options = { "Leave a tribute", "Take an ember for yourself" };
		int choice = ui.DisplayMenuAndPromptUser("What will you do?", options);

		if (choice == 1)
		{
			ui.messageBox("|| The flame dims respectfully and gutters low. ||", 15);
			ui.messageBox("|| Warmth settles into your chest — you feel steadier. ||", 15);
			ui.messageBox("|| You lost a bit of money but gained Mana. ||", 15);
			player.setMoney(std::max(0, player.getMoney() - 30));
			player.setMana(player.getMaxMana() + 25);
			player.setMorale(20);
			storyProgress += 2;
		}
		else
		{
			ui.messageBox("|| The shrine roars upward, furious. ||", 35);

			Monster monster = Monster("Wrathful Ember Elemental", monsterType::ELEMENTAL, 300, 32, 58, 340);
			battleEvent(monster);
			player.setMorale(-20);
		}
		flameCoil = true;
		break;
	}

	case 4:
	{
		ui.messageBox("|| A pale figure kneels beside an unmarked grave, unable to leave it. ||", 15);
		ui.messageBoxWithCharacterName("Pale Figure", "Please... tell my daughter in the village I'm sorry. I never got the chance", 15);
		std::vector<std::string> options = { "Promise to deliver the message", "Disturb the grave for its contents" };
		int choice = ui.DisplayMenuAndPromptUser("What will you do?", options);

		if (choice == 1)
		{
			ui.messageBox("|| The spirit's shoulders ease... ||", 15);
			ui.messageBoxWithCharacterName("Pale Figure", "Thank you...", 55);
			ui.messageBox("|| It whispers, and fades. ||", 15);
			ui.messageBox("|| You gain more HP ||", 15);
			player.setHealth(player.getHealth() + 30);
			player.setMorale(20);
			storyProgress += 2;
		}
		else
		{
			ui.messageBox("|| The ground splits before you can finish digging. ||", 15);

			Monster monster = Monster("Vengeful Spirit", monsterType::UDEAD, 200, 30, 30, 260);
			battleEvent(monster);
			player.setMorale(-20);
		}
		ghost = true;
		break;
	}
	}

	if (oldLadyCheck && wolfEvent && rootMoss && flameCoil && ghost)
	{
		AllStoriesDone = true;
	}
}

void Events::saveGame()
{
	std::ofstream file("save.dat");
	if (!file)
	{
		std::cout << "Could not create save file.\n";
		ui.pause();
		return;
	}

	player.saveToFile(file);
	file << storyProgress << "\n";

	file.close();
	std::cout << "Game saved!\n";
	ui.pause();
}

void Events::loadGame()
{
	std::ifstream file("save.dat");
	if (!file)
	{
		std::cout << "No save file found.\n";
		ui.pause();
		return;
	}

	player.loadFromFile(file);

	std::string line;
	std::getline(file, line);
	storyProgress = std::stoi(line);

	file.close();
	gameMenu();
}

void Events::finalBoss()
{
	ui.messageBoxWithCharacterName("Onyx","Hello... " + player.getName(), 50);
	ui.messageBoxWithCharacterName("Onyx", "Seems like you didn't die after I threw you away from this kingdom.", 20);
	ui.messageBoxWithCharacterName("Onyx", "You made a big mistake coming here...", 30);
	ui.messageBoxWithCharacterName("Onyx", "Now you will face my wrath!", 100);
	Monster boss = Monster("Onyx", monsterType::CELESTIAL, 350, 42, 60, 1500);
	battleEvent(boss);
}

void Events::finalBossWithTrueEnding()
{
	Monster boss = Monster("Dark Gaia", monsterType::CELESTIAL, 400, 42, 60, 2000);
	battleEvent(boss);
}

void Events::trueEnding()
{
	ui.messageBox("|| Onyx falls to the ground... ||", 15);
	ui.messageBox("|| He seems to be weak... ||", 15);
	ui.messageBox(player.getName(), 15);
	ui.messageBox("|| Onyx is begging for mercy... ||", 15);
	ui.messageBox("|| He is begging for a second chance ||", 15);
	std::vector<std::string> mercy = { "Spare Him", "Finish him off" };
	int choice = ui.DisplayMenuAndPromptUser("What will you do?", mercy);
	switch (choice)
	{
	case 1: 
	{
		ui.messageBoxWithCharacterName("Onyx", player.getName() + ", you spared me?", 50);
		ui.messageBox("Thank you...", 50);
		ui.messageBox("|| Suddenly Onyx doesn't feel that great ||", 25);
		ui.messageBox("|| A dark spirit takes over his body ||", 25);
		ui.messageBoxWithCharacterName("Dark Gaia", "I will not let you defeat me " + player.getName(), 125);

		
		finalBossWithTrueEnding();

		break;
	}
	case 2:
	{
		ui.messageBox("You...", 75);
		ui.messageBox("Would kill your own brother?", 75);
		ui.messageBox("How... Could... You...", 75);

		neutralEnding();
	}

	}
}

void Events::neutralEnding()
{
	ui.messageBox("You have defeated Onyx...", 5);
	ui.messageBox("You feel like you are at peace...", 5);
	ui.messageBox("The kingdom is finally freed from all evil.", 5);
	ui.messageBox("You are the true King.", 5);
	saveGame();

	credits();
	mainMenu();

	
}

void Events::finalEnding()
{
	ui.messageBox("|| You have done it ||", 25);
	ui.messageBox("|| You have defeated the true boss. ||", 25);
	ui.messageBox("|| Onyx evil faded away ||", 25);
	ui.messageBoxWithCharacterName("Onyx", "Thank you " + player.getName() + " for saving me...", 25);
	ui.messageBox(" || The kingdom is finally freed from all evil. || ", 25);
	ui.messageBox(" || You two are the true Kings. || ", 25);

	saveGame();
	credits();
	mainMenu();

}

void Events::credits()
{
	ui.clearScreenForGame();
	std::cout << "===================================================================================" << std::endl;
	std::cout << "                        Thank You For Playing my Game!!!!!!                        " << std::endl;
	std::cout << "                                                                                   " << std::endl;
	std::cout << "===================================================================================" << std::endl;
	std::cout << "                                                                                   " << std::endl;
	std::cout << "                                                                                   " << std::endl;
	std::cout << "===================================================================================" << std::endl;
	std::cout << "                         Game Made by: Jose Ruiz/Gamb0yyt                          " << std::endl;
	std::cout << "                         Music Made by: Jose Ruiz/Gamb0yyt                         " << std::endl;
	std::cout << "                         Story Made by: Jose Ruiz/Gamb0yyt                         " << std::endl;
	std::cout << "===================================================================================" << std::endl;
	ui.pause();



} 

