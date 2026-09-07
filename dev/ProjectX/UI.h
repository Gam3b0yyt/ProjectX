#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <thread>
class UI
{
private:
	void ClearScreen();
	


public:
	int DisplayMenuAndPromptUser(std::vector<std::string>& menuOptions);
	void PressEnterToContinue();
};

