#include "Door.h"

void Door::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}
