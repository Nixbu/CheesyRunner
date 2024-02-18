#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f position, sf::Texture* texture,
			float velocity)
	: GameObject(position, texture), m_initPos(position), m_direction(STAND),
	m_velocity(velocity)
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

void MovingObject::setDirection(const sf::Vector2f direction)
{
	m_direction = direction;
}

float MovingObject::getVelocity() const
{
	return m_velocity;
}

void MovingObject::setVelocity(float velocity)
{
	m_velocity = velocity;
}

