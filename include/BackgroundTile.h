#pragma once

#include "StaticObject.h"

/*
	Class BackgroundTile:
		The class represent a background tile in the level
*/
class BackgroundTile : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~BackgroundTile() = default;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);

private:
};