#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f position, sf::Texture* texture)
	: GameObject(position, texture), m_initPos(position)
{
	this->scale(sf::Vector2f(0.25, 0.25));
}

bool MovingObject::isCollided(GameObject& obj) const
{
	return this->getSprite()->getGlobalBounds().intersects(
		obj.getSprite()->getGlobalBounds());
}
