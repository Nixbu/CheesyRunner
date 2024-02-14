#pragma once

#include "MovingObject.h"

class Cat : public MovingObject {
public:
	Cat(sf::Vector2f pos, sf::Texture* texture);
	~Cat() = default;
	void move() override;
	void draw(sf::RenderWindow* window) const override;
private:
	//todo
};