#pragma once

#include "Gift.h"


/*
	Class KillCatGiftl:
		The class represents a present that makes a cat disapear in the game.
*/

class KillCatGift : public Gift {
public:
	using Gift::Gift;
	virtual void action(enum Gift_t& giftType);

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);

private:

};