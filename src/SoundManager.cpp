#include "SoundManager.h"

SoundManager::SoundManager()
{
	sf::SoundBuffer currentSndBffr;

	load(currentSndBffr, "keySound.ogg");
	m_sounds.push_back(currentSndBffr);
    // WORKING - Just need to do it in a function, and for more sounds
    m_keySound.setBuffer(m_sounds[keySound]);
    m_keySound.setVolume(SFX_VOLUME);
}

sf::SoundBuffer* SoundManager::getSoundBuffer(Sound_t sound) const
{
    return (sf::SoundBuffer*)&m_sounds[sound];
}

void SoundManager::playKeySound()
{
    m_keySound.play();
}

void SoundManager::load(sf::SoundBuffer & current, std::string soundName)
{
    if (!current.loadFromFile(soundName))
    {
        std::cout << "failed to load sound " << std::endl;
        exit(EXIT_FAILURE);
    }

}
