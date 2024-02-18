#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Cheese() = default;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handlecollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
private:
};