#pragma once

#include "StaticObject.h"
#include "Settings.h"

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f position, sf::Texture* texture , enum Gift_t giftType);
	virtual ~Gift() = default;

	virtual void draw(sf::RenderWindow* window) const override;
	virtual void action() = 0;
	
private:
	enum Gift_t m_type;
};