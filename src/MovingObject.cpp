#include "MovingObject.h"

// ctor
MovingObject::MovingObject(sf::Vector2f position, sf::Texture* texture,
			float velocity)
	: GameObject(position, texture), m_initPos(position), m_direction(STAND),
	m_velocity(velocity)
{
	this->scale(sf::Vector2f(0.25, 0.25));
	this->getSprite()->setOrigin(sf::Vector2f(this->getSprite()->getLocalBounds().width / 2,
		this->getSprite()->getLocalBounds().height / 2));
}
//======================================================
// function checks if 2 objects collided
bool MovingObject::isCollided(GameObject& obj) const
{
	return this->getSprite()->getGlobalBounds().intersects(
		obj.getSprite()->getGlobalBounds());
}
//======================================================
sf::Vector2i MovingObject::getDirection() const
{
	return m_direction;
}
//======================================================
void MovingObject::setDirection(const sf::Vector2i direction)
{
	m_direction = direction;
}
//======================================================
float MovingObject::getVelocity() const
{
	return m_velocity;
}
//======================================================
void MovingObject::setVelocity(float velocity)
{
	m_velocity = velocity;
}
//======================================================
void MovingObject::resetPosition()
{
	this->getSprite()->setPosition(m_initPos);
}
//======================================================
void MovingObject::setInitPos(const sf::Vector2f &pos)
{
	m_initPos = pos;
}

