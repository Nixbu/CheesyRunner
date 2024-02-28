#pragma once

#include "StaticObject.h"
#include "Mouse.h"

/*
	Class Cheese:
		The class represents the cheese in the game.
*/

class Cheese : public StaticObject {
public:
	Cheese(sf::Vector2f position, sf::Texture* texture);
	virtual ~Cheese() ;

	static int getCount(); 
	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
private:
	static int m_count;
};



