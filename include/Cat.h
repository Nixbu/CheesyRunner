#pragma once

#include "MovingObject.h"

class Cat : public MovingObject {
public:
	using MovingObject::MovingObject;
	~Cat() = default;
	void move(sf::Vector2f direction, float deltaTime) override;
	void draw(sf::RenderWindow* window) const override;
private:
	//todo
};