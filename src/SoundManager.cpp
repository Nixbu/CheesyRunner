#include "SoundManager.h"

SoundManager::SoundManager()
{
	sf::SoundBuffer currentSndBffr;

	load("keySound.ogg", keySound);
    // WORKING - Just need to do it in a function, and for more sounds
   
}

sf::SoundBuffer* SoundManager::getSoundBuffer(Sound_t sound) const
{
    return (sf::SoundBuffer*)&m_sounds[sound];
}

void SoundManager::playSound(Sound_t soundNum)
{
    m_sounds[soundNum].play();
}

void SoundManager::load(std::string soundName, Sound_t soundNum)
{
    sf::SoundBuffer current;
    sf::Sound currSound;
    if (!current.loadFromFile(soundName))
    {
        std::cout << "failed to load sound " << std::endl;
        exit(EXIT_FAILURE);
    }

    m_soundBuffers.push_back(current);

    currSound.setBuffer(m_soundBuffers[soundNum]);
    currSound.setVolume(SFX_VOLUME);
    m_sounds.push_back(currSound);

}
