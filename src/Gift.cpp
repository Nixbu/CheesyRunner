#include "Gift.h"

Gift::Gift(sf::Vector2f position, sf::Texture* texture) :
	StaticObject(position , texture) 
{
}

void Gift::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}




