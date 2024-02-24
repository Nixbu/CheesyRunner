#pragma once

#include "StaticObject.h"
#include "Mouse.h"

class Cheese : public StaticObject {
public:
	Cheese(sf::Vector2f position, sf::Texture* texture,
		sf::SoundBuffer* soundBffr);
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



