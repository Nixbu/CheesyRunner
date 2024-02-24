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

private:
	std::vector<sf::SoundBuffer> m_sounds;

	void load(sf::SoundBuffer& current, std::string texture_name);

};