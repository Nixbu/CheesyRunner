#include "Wall.h"

void Wall::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}
