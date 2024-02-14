#include "Key.h"

void Key::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}
