#include "TimeGift.h"
//======================================================
// ctor
void TimeGift::action(enum Gift_t& giftType)
{
	giftType = addTime;
}
//======================================================
void TimeGift::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void TimeGift::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}