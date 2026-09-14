#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
class UI
{
private:
	void ClearScreen();
	void PressEnterToContinue();
	void Border();

public:
	int DisplayMenuAndPromptUser(std::string title,std::vector<std::string>& menuOptions);
	void messageBox(std::string message);
	
};

