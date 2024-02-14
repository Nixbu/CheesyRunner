#include "Door.h"
include "Door.h"

void Door::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}
