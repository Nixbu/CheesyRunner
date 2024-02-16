#include "StaticObject.h"

void StaticObject::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}