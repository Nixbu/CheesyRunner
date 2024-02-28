#include "StaticObject.h"


//======================================================
// ctor
StaticObject::StaticObject(sf::Vector2f position, sf::Texture* texture) :
	GameObject(position, texture)
{
	this->scale(sf::Vector2f(0.375f, 0.375f));
}