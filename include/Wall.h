#pragma once

#include "StaticObject.h"
#include "Mouse.h"
#include "Cat.h"

/*
	Class Wall:
		The class represents a wall in the game.
*/

class Wall : public StaticObject {
public:
	using StaticObject::StaticObject;
	~Wall() = default;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);


private:
};