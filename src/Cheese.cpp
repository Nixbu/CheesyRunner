#pragma once 

#include "Cheese.h"

void Cheese::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}