#pragma once

#include "StaticObject.h"

class Cheese : public StaticObject {
public:
	using StaticObject::StaticObject;
	~Cheese() = default;

	void draw(sf::RenderWindow * window) override;
private:
};