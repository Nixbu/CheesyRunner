#include "Mouse.h"

Mouse::Mouse(sf::Vector2f position, sf::Texture* texture,
	float velocity)
	: MovingObject(position, texture, MOUSE_VELOCITY),
	m_keys(0), m_life(3), m_score(0),
	m_numOfCheese(0)
{
}

void Mouse::setKeys(int keys)
{
	this->m_keys = keys;
}

void Mouse::setCheese(int cheese)
{
	this->m_numOfCheese = cheese;
}

int Mouse::getCheese() const
{
	return this->m_numOfCheese;
}

int Mouse::getKeys() const
{
	return this->m_keys;
}

void Mouse::move(sf::Vector2f direction, float deltaTime)
{
	this->setDirection(direction);

	this->getSprite()->move(this->getDirection().x * deltaTime * this->getVelocity(),
		this->getDirection().y * deltaTime * this->getVelocity());
}

void Mouse::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}

void Mouse::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	// double dispatch
	gameObject.handleCollision(*this, intersection);
}

void Mouse::handleCollision(Mouse& gameobject, sf::FloatRect intersection)
{
}

void Mouse::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
	m_score += CHEESE_SCORE;
}

void Mouse::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}

void Mouse::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void Mouse::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}

void Mouse::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
	this->getSprite()->move((-1) * intersection.width * this->getDirection().x,
		(-1) * intersection.height * this->getDirection().y);
}


