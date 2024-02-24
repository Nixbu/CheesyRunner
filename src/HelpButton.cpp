#include "HelpButton.h"

void HelpButton::action(sf::RenderWindow* window, 
	const TextureManager& textures,
	const SoundManager& sounds)
{
	sf::Sound sound;
	sound.setBuffer(*sounds.getSoundBuffer(keySound));
	sound.play();
}
