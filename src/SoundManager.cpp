#include "SoundManager.h"

SoundManager::SoundManager()
{
	sf::SoundBuffer currentSndBffr;

	load(currentSndBffr, "keySound.ogg");
	m_sounds.push_back(currentSndBffr);
}

sf::SoundBuffer* SoundManager::getSoundBuffer(Sound_t sound) const
{
    return (sf::SoundBuffer*)&m_sounds[sound];
}

void SoundManager::load(sf::SoundBuffer & current, std::string soundName)
{
    if (!current.loadFromFile(soundName))
    {
        std::cout << "failed to load sound " << std::endl;
        exit(EXIT_FAILURE);
    }
}
