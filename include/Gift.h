#pragma once

#include "StaticObject.h"
#include "Settings.h"

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f position, sf::Texture* texture , enum Gift_t giftType);
	virtual ~Gift() = default;

	virtual void draw(sf::RenderWindow* window) override;
	
private:
	enum Gift_t m_type;
};