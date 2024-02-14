#pragma once

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	using StaticObject::StaticObject;
	~Wall() = default;

	void draw(sf::RenderWindow* window) override;
private:
};