#include "Mouse.h"

Mouse::Mouse(sf::Vector2f pos, sf::Texture* texture)
	: MovingObject(pos, texture),
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

void Mouse::move(sf::Vector2f direction, sf::Time delta_time)
{
	this->setDirection(direction);

	this->getSprite()->move();
}

void Mouse::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}

void Mouse::setDirection(sf::Vector2f direction)
{
	sf::Vector2f def = UP;

	if (direction == UP && this->getDirection() != UP)
	{
		
	}
}

