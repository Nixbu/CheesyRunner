#pragma once

#include "StaticObject.h"
#include "Settings.h"

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f position, sf::Texture* texture);
	virtual ~Gift() = default;

	virtual void action(enum Gift_t &giftType) = 0;	
private:
};