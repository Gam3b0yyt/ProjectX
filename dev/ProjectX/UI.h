#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
class UI
{
private:
	void ClearScreen();
	void PressEnterToContinue();
	void Border();
	void typeWriterEffect(std::string message, int time);

public:
	int DisplayMenuAndPromptUser(std::string title,std::vector<std::string>& menuOptions);
	int DisplayMenuAndPromptUserWithoutClearing(std::string title, std::vector<std::string>& menuOptions);
	void messageBox(std::string message, int speed);
	void messageBoxWithCharacterName(std::string CharacterName, std::string message, int speed);
	void clearScreenForGame();
	void pause();
	
};

