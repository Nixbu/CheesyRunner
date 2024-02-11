#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position, 
	sf::Texture * texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
}
