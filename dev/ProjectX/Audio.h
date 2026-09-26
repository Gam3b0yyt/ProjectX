#pragma once
#include <string>
#include <vector>

class Audio
{
private:
	void playMusic(const std::string& path);

public:
	void playTitleMusic();
	void playExploreMusic();
	void playRandomEnemySong();
	void playOnyxTheme();
	void playDarkGaiaTheme();
	void stopMusic();
};

