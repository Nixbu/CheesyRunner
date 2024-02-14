#include "Wall.h"

void Wall::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite()); 
}
