#include "FreezeGift.h"
//======================================================
// setting the freeze gift flag
void FreezeGift::action(enum Gift_t& giftType)
{
	giftType = freeze;
}

//======================================================
void FreezeGift::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void FreezeGift::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}