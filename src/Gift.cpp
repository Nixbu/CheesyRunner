#include "Gift.h"


// cttor
Gift::Gift(sf::Vector2f position, sf::Texture* texture) :
	StaticObject(position , texture) 
{
	this->getSprite()->scale(0.4f, 0.4f);
}



