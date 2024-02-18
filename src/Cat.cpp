#include "Cat.h"

void Cat::move(sf::Vector2f direction, float deltaTime)
{
}

void Cat::draw(sf::RenderWindow* window) const
{
	window->draw(*(this->getSprite()));
}
