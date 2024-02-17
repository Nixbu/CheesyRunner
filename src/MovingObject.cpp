#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f position, sf::Texture* texture)
	: GameObject(position, texture), m_initPos(position), m_direction()
{
	this->scale(sf::Vector2f(0.25, 0.25));
}

bool MovingObject::isCollided(GameObject& obj) const
{
	return this->getSprite()->getGlobalBounds().intersects(
		obj.getSprite()->getGlobalBounds());
}

sf::Vector2f MovingObject::getDirection() const
{
	return m_direction;
}
