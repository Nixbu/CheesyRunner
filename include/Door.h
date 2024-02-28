#pragma once

#include "StaticObject.h"

#include "Mouse.h"
#include "Cat.h"

/*
	Class Door:
		The class represents the door in the game.
*/

class Door : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Door() = default;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);

private:
};