#define NOMINMAX
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

#include "Audio.h"
#include "Tracks.h"
#include <cstdlib>


void Audio::playMusic(const std::string& path)
{
	PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Audio::stopMusic()
{
	PlaySoundA(NULL, NULL, 0);
}

void Audio::playTitleMusic()
{
	playMusic(Music::Title);
}

void Audio::playExploreMusic()
{
	playMusic(Music::LynxTheme);
}

void Audio::playRandomEnemySong()
{
	static const std::vector<std::string> enemyThemes = {
		Music::RubyOverdrive, Music::SilverCircuit, Music::HeartByteQueen
	};
	int index = std::rand() % enemyThemes.size();
	playMusic(enemyThemes[index]);
}

void Audio::playOnyxTheme()
{
	playMusic(Music::AidanTheme);
}

void Audio::playDarkGaiaTheme()
{
	playMusic(Music::BrotherTheme);
}