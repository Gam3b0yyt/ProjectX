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


public:
	int DisplayMenuAndPromptUser(std::vector<std::string>& menuOptions);

};

