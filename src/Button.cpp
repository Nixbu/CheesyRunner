#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture* texture) :
	GameObject( position , texture)
{
	//this->getSprite()->setScale(BUTTON_SCALE, BUTTON_SCALE);
}

bool Button::isClicked(sf::Vector2f mousePosition) const
{
	
}
