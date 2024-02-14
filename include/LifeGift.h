#pragma once

#include "Gift"
#include "Settings.h"

class LifeGift : public Gift {
public:
	using Gift::Gift;
	virtual ~LifeGift() = default;

	virtual void draw(sf::RenderWindow* window) const override;
	virtual void action() override;

private:
};