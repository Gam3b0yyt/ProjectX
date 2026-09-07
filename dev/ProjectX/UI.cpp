#include "UI.h"

void UI::ClearScreen()
{
	system("cls");
}

void UI::PressEnterToContinue()
{
	std::cout << "Press enter to continue...";
	std::cin.get();
}

int UI::DisplayMenuAndPromptUser(std::vector<std::string>& menuOptions)
{
	int choice = 0;
	std::string tempChoice = "";

	do {

		for (int i = 0; i < menuOptions.size(); i++) {
			std::cout << "[" + std::to_string(i + 1) + "] " << menuOptions[i] << std::endl;
		}

		std::cout << "\nChoice: ";

		getline(std::cin, tempChoice);
		choice = std::stoi(tempChoice);

		if (choice < 1 || choice > menuOptions.size());
		{
			std::cout << "Invalid menu selection. Please try again.\n\n";

			PressEnterToContinue();
		}

		return choice;
	} while (choice < 1 || choice > menuOptions.size());
}
