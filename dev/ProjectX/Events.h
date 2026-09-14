#pragma once
#include "UI.h"
#include "Player.h"
class Events
{
private:

	UI ui;

	Player player;
	int storyProgress;
	

public:

	void settings();

	void mainMenu();

	void CreatePlayer();

	void newGame();

	void gameMenu();

};

