#include "Button.h"

//===================================================================
Button::Button(sf::Vector2f position, sf::Texture* texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
}

//===================================================================
const sf::Sprite* Button::getSprite() const
{
	return nullptr;
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

void Button::resize(sf::Vector2f wanted_size)
{
	this->scale(wanted_size.x / (*this->getSprite()).getGlobalBounds().width,
		wanted_size.y / this->getSprite()->getGlobalBounds().height);
}

//===================================================================
void Button::scale(const sf::Vector2f& values)
{
	this->m_sprite.setScale(values);
}

//===================================================================
void Button::setPos(const sf::Vector2f& newPos)
{
	this->m_sprite.setPosition(newPos);
}
