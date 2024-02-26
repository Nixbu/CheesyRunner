#pragma once

#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <string>
#include <Settings.h>

class SoundManager {
public:
	SoundManager();
	~SoundManager() = default;

	sf::SoundBuffer * getSoundBuffer(Sound_t sound) const;
	void playSound(Sound_t soundNum);

private:
	std::vector<sf::SoundBuffer> m_soundBuffers;
	std::vector<sf::Sound> m_sounds;
	sf::Sound m_keySound;

	void load(std::string texture_name,
		Sound_t soundNum);

};