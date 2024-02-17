#include "Cat.h"

void Cat::move()
{
}

void Cat::draw(sf::RenderWindow* window) const
{
	window->draw(*(this->getSprite()));
}
