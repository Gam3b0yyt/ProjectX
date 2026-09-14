#include "Events.h"


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
		player.setHealth(130); player.setAttack(16); player.setDefense(9); player.setMana(25); break;
	case characterTypes::SORCERER:
		player.setHealth(80); player.setAttack(12); player.setDefense(3); player.setMana(100); break;
	case characterTypes::BARBARIAN:
		player.setHealth(150); player.setAttack(20); player.setDefense(4); player.setMana(20); break;
	case characterTypes::MONK:
		player.setHealth(105); player.setAttack(17); player.setDefense(6); player.setMana(45); break;
	case characterTypes::FIGHTER:
		player.setHealth(115); player.setAttack(18); player.setDefense(7); player.setMana(30); break;
	case characterTypes::CLERIC:
		player.setHealth(95); player.setAttack(13); player.setDefense(5); player.setMana(75); break;
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

}

void Events::gameMenu()
{

}
