#include "BackgroundTile.h"

void BackgroundTile::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}
