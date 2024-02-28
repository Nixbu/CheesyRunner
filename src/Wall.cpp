#include "Wall.h"

//======================================================
//ctor
void Wall::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	
}
//======================================================
void Wall::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}
//======================================================
void Wall::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Wall::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Wall::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Wall::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Wall::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
