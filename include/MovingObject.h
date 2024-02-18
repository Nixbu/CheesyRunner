#pragma once

#include "GameObject.h"

class MovingObject: public GameObject {
public:
	MovingObject(sf::Vector2f position, sf::Texture* texture,
		float velocity);
	virtual ~MovingObject() = default;

	bool isCollided(GameObject& obj) const;
	virtual void move(sf::Vector2f direction, float deltaTime) = 0;
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f);
	float getVelocity() const;
	void setVelocity(float velocity);

private:
	sf::Vector2f m_initPos,
		m_direction;
	float m_velocity;
};