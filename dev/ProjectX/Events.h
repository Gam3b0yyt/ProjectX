#pragma once
#include "UI.h"
#include "Player.h"
#include <random>
#include "Monster.h"
#include "Shop.h"
class Events
{
private:

	UI ui;

	

	Player player;
	
	int storyProgress = 0;

	

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

	void battle(Monster enemy);
	void battleEvent(Monster enemy);
	void playersTurn(Monster& enemy);
	void monsterTurn(Monster& enemy);

	void showMonsterStats(Monster enemy);

	void StoryEvents();
};

