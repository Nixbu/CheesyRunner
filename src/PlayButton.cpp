#include "PlayButton.h"

//========================================
// Play the game
void PlayButton::action(sf::RenderWindow* window,
	const TextureManager& textures)
{
	Game game((TextureManager *)(&textures), window);
	game.run();

	window->create(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Mouse And Cat");

	
}
