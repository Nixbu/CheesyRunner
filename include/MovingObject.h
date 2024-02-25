#pragma once

#include "GameObject.h"

class MovingObject: public GameObject {
public:
	MovingObject(sf::Vector2f position, sf::Texture* texture,
		float velocity);
	virtual ~MovingObject() = default;

	bool isCollided(GameObject& obj) const;
	
	sf::Vector2i getDirection() const;
	void setDirection(const sf::Vector2i);
	float getVelocity() const;
	void setVelocity(float velocity);

private:
	sf::Vector2f m_initPos; 
	sf::Vector2i m_direction;
	float m_velocity;
};