#pragma once
#include "UI.h"
#include "Player.h"
#include <random>
#include "Monster.h"
#include "Shop.h"
#include "Audio.h"
class Events
{
private:

	UI ui;

	Audio sound;

	Player player;
	
	int storyProgress = 0;

	bool oldLadyCheck = false;
	bool wolfEvent = false;
	bool rootMoss = false;
	bool flameCoil = false;
	bool ghost = false;

	bool AllStoriesDone = false;

	

public:

	void Intro();

	void Title();

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
	bool playersTurn(Monster& enemy);
	void monsterTurn(Monster& enemy);

	void showMonsterStats(Monster enemy);

	void StoryEvents();

	void saveGame();
	void loadGame();

	void finalBoss();
	void finalBossWithTrueEnding();

	void trueEnding();
	void neutralEnding();
	void finalEnding();

	void credits();

};

