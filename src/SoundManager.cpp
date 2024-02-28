#include "SoundManager.h"

// ctor
SoundManager::SoundManager()
{
	load("keySound.ogg", keySound);
    load("doorSound.ogg", doorSound);
    load("gotHitSound.ogg", gotHitSound);
    load("cheeseSound.ogg", cheeseSound);
    load("lifeGiftSound.ogg", lifeGiftSound);
    load("timeGiftSound.ogg", timeGiftSound);
    load("killCatGiftSound.ogg", killCatGiftSound);
    load("freezeGiftSound.ogg", freezeGiftSound);
    load("loseFromTimeSound.ogg", loseFromTimeSound);
    load("loseSound.ogg", loseSound);
    load("winSound.ogg", winSound);

}
//======================================================
SoundManager::~SoundManager()
{
    for (int idx = 0; idx < m_soundBuffers.size(); idx++)
    {
        delete m_soundBuffers[idx];
    }
}
//======================================================
sf::SoundBuffer* SoundManager::getSoundBuffer(Sound_t sound) const
{
    return (sf::SoundBuffer*)&m_sounds[sound];
}
//======================================================
void SoundManager::playSound(Sound_t soundNum)
{
    m_sounds[soundNum].play();
}
//======================================================
void SoundManager::load(std::string soundName, Sound_t soundNum)
{
    sf::SoundBuffer * current = new sf::SoundBuffer;
    sf::Sound currSound;
    if (!current->loadFromFile(soundName))
    {
        std::cout << "failed to load sound " << std::endl;
        exit(EXIT_FAILURE);
    }

    m_soundBuffers.push_back(current);

    currSound.setBuffer(*m_soundBuffers[soundNum]);
    currSound.setVolume(SFX_VOLUME);
    m_sounds.push_back(currSound);

}
