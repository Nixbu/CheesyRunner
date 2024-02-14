#pragma once

#include "StaticObject.h"

class Key : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~Key() = default;

	virtual void draw(sf::RenderWindow* window) override;
private:

};