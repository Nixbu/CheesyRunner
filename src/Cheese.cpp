#pragma once 

#include "Cheese.h"

void Cheese::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}