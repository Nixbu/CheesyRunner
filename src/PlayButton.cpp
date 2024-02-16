#include "PlayButton.h"

//========================================
// Play the game
void PlayButton::action(sf::RenderWindow* window)
{
	Game game;
	game.run();

	window->create(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Mouse And Cat");

	
}
