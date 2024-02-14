#pragma once

#include "StaticObject.h"

class Door : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Door() = default;

	virtual void draw(sf::RenderWindow* window) const override;
private:
};