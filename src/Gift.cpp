#include "Gift.h"

Gift::Gift(sf::Vector2f position, sf::Texture* texture,
	sf::SoundBuffer * soundBffr) :
	StaticObject(position , texture, soundBffr) 
{
	this->getSprite()->scale(0.4f, 0.4f);
}

void Gift::draw(sf::RenderWindow* window)
{
	window->draw(*this->getSprite());
}




