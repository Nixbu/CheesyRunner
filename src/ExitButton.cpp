#include "ExitButton.h"

void ExitButton::action(sf::RenderWindow* window, const TextureManager& textures)
{
	(*window).close();
}
