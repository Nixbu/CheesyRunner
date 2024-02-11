#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture* texture) :
	GameObject( position , texture)
{
	this->getSprite()->getScale(sf::Vector2f{ BUTTON_SCALE ,BUTTON_SCALE });
}

bool Button::isClicked(sf::Vector2f mousePosition) const
{
	
}
