#include "ExitButton.h"


// exiting the window when pressed
void ExitButton::action(sf::RenderWindow* window, const TextureManager& textures,
	const SoundManager& sounds)
{
	(*window).close();
}
