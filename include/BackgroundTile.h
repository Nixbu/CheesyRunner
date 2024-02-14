#pragma once

#include "StaticObject.h"

class BackgroundTile : public StaticObject {
public:
	using StaticObject::StaticObject;
	virtual ~BackgroundTile() = default;

	virtual void draw(sf::RenderWindow* window) const override;
private:
};