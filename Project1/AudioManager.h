#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <array>
#include "GameConfig.h"

class AudioManager {
public:
	AudioManager();
	//Now, map, unique_ptr and SFML have correct manners to clean this object
	~AudioManager() = default;
	void playSound(const char* audioFile, bool toLoop, float volume = 50.0);
	void stopSound(const char* audioFile);
	void pauseSound(const char* audioFile);
	void resumeSound(const char* audioFile);
	void playRandomTileDestroySound();

private:
	void fillAudiosMap();

private:
	const std::array<const char*, 6> audioFiles = {
		AudioConfig::BACKGROUND_MUSIC,
		AudioConfig::TILES_DESTROYED_SOUND_1,
		AudioConfig::TILES_DESTROYED_SOUND_2,
		AudioConfig::TILES_DESTROYED_SOUND_3,
		AudioConfig::TILES_DESTROYED_SOUND_4,
		AudioConfig::WIN_MUSIC
	};
	std::map<const char*, std::unique_ptr<sf::Music>> audiosWithMusics;
};

#endif // AUDIO_MANAGER_H
