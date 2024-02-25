#include "SoundManager.h"

SoundManager::SoundManager()
{
	sf::SoundBuffer currentSndBffr;

	load(currentSndBffr, "keySound.ogg");
	m_sounds.push_back(currentSndBffr);

    sf::Sound sound;

    sound.setBuffer(m_sounds[keySound]);
    sound.setVolume(100);
    sound.play();
}

sf::SoundBuffer* SoundManager::getSoundBuffer(Sound_t sound) const
{
    return (sf::SoundBuffer*)&m_sounds[sound];
}

void SoundManager::playKeySound()
{
    m_keySound.setBuffer(m_sounds[keySound]);
    m_keySound.play();
    std::cout << "Got key\n";

}

void SoundManager::load(sf::SoundBuffer & current, std::string soundName)
{
    if (!current.loadFromFile(soundName))
    {
        std::cout << "failed to load sound " << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Loaded key succesfully\n";

}
