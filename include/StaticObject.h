#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject(sf::Vector2f position, sf::Texture* texture);
	virtual ~StaticObject() = default;

	virtual void draw(sf::RenderWindow* window) const;

private:
};