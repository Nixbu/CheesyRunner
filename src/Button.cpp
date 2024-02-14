#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture* texture) :
	GameObject( position , texture)
{
	/*this->getSprite()-> */
}

bool Button::isClicked(sf::Vector2f mousePosition) const
{
	return false; // TODO
}
