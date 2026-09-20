#pragma once
#include "UI.h"
#include "Player.h"
#include <random>
#include "Monster.h"
class Events
{
private:

	UI ui;

	Player player;
	int storyProgress;
	

public:

	void Intro();

	void Title();

	void settings();

	void mainMenu();

	void CreatePlayer();

	void newGame();

	void gameMenu();

	void showStats();

	void finalBossCheck();

	void explore();

	Monster createRandomMonster() const;
};

