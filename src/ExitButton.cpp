#include "ExitButton.h"

void ExitButton::action(sf::RenderWindow* window, const TextureManager& textures,
	const SoundManager& sounds)
{
	(*window).close();
}
