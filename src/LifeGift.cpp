#include "LifeGift.h"
//======================================================
void LifeGift::action(enum Gift_t& giftType)
{
	giftType = addLife;
}

//======================================================
void LifeGift::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void LifeGift::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}