#pragma once

#include "StaticObject.h"
#include "Settings.h"

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f position, sf::Texture* texture , enum Gift_t giftType);
	virtual ~Gift() = default;

	virtual void action();

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handlecollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
	
private:
	enum Gift_t m_type;
};