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

void UI::Border()
{
	std::cout << "==================================================";
}

int UI::DisplayMenuAndPromptUser(std::string _title, std::vector<std::string>& menuOptions)
{
	int choice = 0;
	std::string tempChoice = "";
	std::string title = _title;

	do {
		ClearScreen();

		std::cout << title << std::endl;

		for (int i = 0; i < menuOptions.size(); i++) {
			std::cout << "[" + std::to_string(i + 1) + "] " << menuOptions[i] << std::endl;
		}

		std::cout << "\nChoice: ";

		getline(std::cin, tempChoice);

		bool isValidNumber = true;


		if (tempChoice.length() == 0) {
			isValidNumber = false;
		}

		for (int i = 0; i < tempChoice.length(); i++) {
			if (tempChoice[i] < '0' || tempChoice[i] > '9') {
				isValidNumber = false;
				break;
			}
		}
		if (isValidNumber)
		{
			choice = std::stoi(tempChoice);
		}
		else {
			choice = 0;
		}


		if (choice < 1 || choice > menuOptions.size())
		{
			std::cout << "Invalid menu selection. Please try again.\n\n";

			PressEnterToContinue();
		}

		
	} while (choice < 1 || choice > menuOptions.size());

	return choice;
}

int UI::DisplayMenuAndPromptUserWithoutClearing(std::string _title, std::vector<std::string>& menuOptions)
{
	int choice = 0;
	std::string tempChoice = "";
	std::string title = _title;

	do {


		std::cout << title << std::endl;

		for (int i = 0; i < menuOptions.size(); i++) {
			std::cout << "[" + std::to_string(i + 1) + "] " << menuOptions[i] << std::endl;
		}

		std::cout << "\nChoice: ";

		getline(std::cin, tempChoice);
		
		bool isValidNumber = true;


		if (tempChoice.length() == 0) {
			isValidNumber = false;
		}

		for (int i = 0; i < tempChoice.length(); i++) {
			if (tempChoice[i] < '0' || tempChoice[i] > '9') {
				isValidNumber = false;
				break;
			}
		}
		if (isValidNumber)
		{
			choice = std::stoi(tempChoice);
		}
		else {
			choice = 0;
		}


		if (choice < 1 || choice > menuOptions.size())
		{
			std::cout << "Invalid menu selection. Please try again.\n\n";

			PressEnterToContinue();
		}


	} while (choice < 1 || choice > menuOptions.size());

	return choice;
}

void UI::messageBox(std::string message)
{
	ClearScreen();
	Border();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << message << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	Border();
	std::cout << "\n";
	PressEnterToContinue();

}

void UI::clearScreenForGame()
{
	ClearScreen();
}

void UI::pause()
{
	PressEnterToContinue();
}

