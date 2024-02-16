#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~StaticObject() = default;

	virtual void draw(sf::RenderWindow* window) const;

private:
};