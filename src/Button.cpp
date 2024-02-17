#include "Button.h"

//===================================================================
Button::Button(sf::Vector2f position, sf::Texture* texture)
	: m_sprite()
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2));
	

}

//===================================================================
const sf::Sprite* Button::getSprite() const
{
	return &m_sprite;
}

//===================================================================
bool Button::isClicked(sf::Vector2f mousePosition) const
{
	return this->getSprite()->getGlobalBounds().contains(mousePosition);
}

//===================================================================
void Button::draw(sf::RenderWindow* window) const
{
	window->draw(*getSprite());
}

//===================================================================
////void Button::resize(sf::Vector2f wantedSize)
//{
//	this->scale(sf::Vector2f(wantedSize.x / this->getSprite()->getGlobalBounds().width,
//		wantedSize.y / this->getSprite()->getGlobalBounds().height));
//}

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
