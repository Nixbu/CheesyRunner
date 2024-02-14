#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture* texture) :
	GameObject( position , texture)
{
	// optional
	this->scale(BUTTON_SCALE);
}
//===================================================================
bool Button::isClicked(sf::Vector2f mousePosition) const
{
	return this->getSprite()->getGlobalBounds().contains(mousePosition);
}
//===================================================================
void Button::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}
