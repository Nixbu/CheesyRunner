#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f position, sf::Texture* texture) :
	GameObject(position, texture)
{
	this->scale(sf::Vector2f(0.33f, 0.33f));
}

void StaticObject::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}