#include "Events.h"

void Events::mainMenu()
{
	std::vector<std::string> mainMenuChoices = {
		"New Game", "Load Game", "Settings", "Exit"
	};

	int choice = 0;

	do {
		choice = ui.DisplayMenuAndPromptUser(mainMenuChoices);

		switch (choice) {
		case 1: // Starts a new Game
			break;
		case 2: // Loads the save file 
			break;
		case 3: // Goes to the settings Menu
			break;
		case 4: // Will exit the program
			break;
		default:
			break;
		}

	} while (choice != 4);


}
