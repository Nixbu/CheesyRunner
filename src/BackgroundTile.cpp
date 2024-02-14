#include "BackgroundTile.h"

void BackgroundTile::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}
