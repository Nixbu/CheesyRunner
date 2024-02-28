#include "GameObject.h"
//======================================================
GameObject::GameObject(sf::Vector2f position, 
	sf::Texture * texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
	
}
//======================================================
sf::Sprite* GameObject::getSprite() const
{
	return (sf::Sprite *) & m_sprite;
}
//======================================================
void GameObject::scale(const sf::Vector2f &values)
{
	this->m_sprite.setScale(values);
}
//======================================================
void GameObject::setPos(const sf::Vector2f &newPos)
{
	this->m_sprite.setPosition(newPos);
	
}

//======================================================
void GameObject::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}
