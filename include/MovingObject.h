#pragma once

#include "GameObject.h"

class MovingObject: public GameObject {
public:
	MovingObject(sf::Vector2f position, sf::Texture* texture);
	virtual ~MovingObject() = default;

	bool isCollided(GameObject& obj) const;
	virtual void move() = 0;
	sf::Vector2f getDirection() const;

private:
	sf::Vector2f m_initPos,
		m_direction;
};