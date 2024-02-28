#include "KillCatGift.h"

// function sets the cat kill flag
void KillCatGift::action(enum Gift_t& giftType)
{
	giftType = killCat;
}
//======================================================
void KillCatGift::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void KillCatGift::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}