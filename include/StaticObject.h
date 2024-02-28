#pragma once

#include "GameObject.h"
#include "SFML/Audio.hpp"


class StaticObject : public GameObject
{
public:
	StaticObject(sf::Vector2f position, sf::Texture* texture);
	virtual ~StaticObject() = default;

private:
};