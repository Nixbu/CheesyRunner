#include "Key.h"

void Key::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}
