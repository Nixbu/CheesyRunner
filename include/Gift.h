#pragma once

#include "StaticObject.h"
#include "Settings.h"

/*
	Class Gift:
		The class represents the gift objects in the game.
		The class is abstract.
*/

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f position, sf::Texture* texture);
	virtual ~Gift() = default;

	virtual void action(enum Gift_t &giftType) = 0;	
private:
};