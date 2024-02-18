#pragma once

#include "MovingObject.h"

class Cat : public MovingObject {
public:
	using MovingObject::MovingObject;
	~Cat() = default;
	void move(sf::Vector2f direction, float deltaTime) override;
	void draw(sf::RenderWindow* window) const override;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
private:
	//todo
};