#include "Key.h"

void Key::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}
//======================================================
void Key::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}
//======================================================
void Key::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Key::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Key::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Key::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Key::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
