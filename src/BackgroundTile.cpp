#include "BackgroundTile.h"

void BackgroundTile::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}

void BackgroundTile::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}

void BackgroundTile::handlecollision(Mouse& gameobject, sf::FloatRect intersection)
{
}

void BackgroundTile::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}

void BackgroundTile::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}

void BackgroundTile::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void BackgroundTile::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}

void BackgroundTile::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
