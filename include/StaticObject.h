#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	~StaticObject() = default;

	virtual void draw(sf::RenderWindow* window) = 0;
private:
};