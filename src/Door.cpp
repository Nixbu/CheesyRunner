#include "Door.h"

//======================================================
void Door::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}
//======================================================
void Door::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}
//======================================================
void Door::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Door::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Door::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Door::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Door::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
