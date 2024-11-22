#include "AudioManager.h"
#include <array>

AudioManager::AudioManager() {
	fillAudiosMap();
}

void AudioManager::fillAudiosMap() {
	int arraySize = audioFiles.size();
	for (int i = 0; i < arraySize; i++) {
		auto audio = std::make_unique<sf::Music>();
		audiosWithMusics[audioFiles[i]] = std::move(audio);
	}
}

void AudioManager::playSound(const char* audioFile, bool toLoop, float volume) {
	if (audiosWithMusics[audioFile]->openFromFile(audioFile)) {
		audiosWithMusics[audioFile]->setLoop(toLoop);
		audiosWithMusics[audioFile]->play();
		audiosWithMusics[audioFile]->setVolume(volume);
	}
}

void AudioManager::stopSound(const char* audioFile) {
	audiosWithMusics[audioFile]->stop();
}

void AudioManager::pauseSound(const char* audioFile) {
	audiosWithMusics[audioFile]->pause();
}

void AudioManager::resumeSound(const char* audioFile) {
	audiosWithMusics[audioFile]->play();
}

void AudioManager::playRandomTileDestroySound() {
	std::array<const char*, 4> tileSounds = {
		AudioConfig::TILES_DESTROYED_SOUND_1,
		AudioConfig::TILES_DESTROYED_SOUND_2,
		AudioConfig::TILES_DESTROYED_SOUND_3,
		AudioConfig::TILES_DESTROYED_SOUND_4
	};
	std::srand(static_cast<unsigned>(std::time(0)));
	int random_number = std::rand() % tileSounds.size();
	playSound(tileSounds[random_number], false);
}