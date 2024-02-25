#include "Mouse.h"

Mouse::Mouse(sf::Vector2f position, sf::Texture* texture,
	float velocity,
	SoundManager * sounds)
	: MovingObject(position, texture, MOUSE_VELOCITY),
	m_keys(0), m_life(SOULS_NUM), m_score(0),
	m_numOfCheese(0)
{
	m_sounds = sounds;
}

void Mouse::setKeys(int keys)
{
	this->m_keys = keys;
}

void Mouse::addKey()
{
	m_keys++;
}

void Mouse::removeKey()
{
	m_keys--;
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

int Mouse::getSouls() const
{
	return m_life;
}

int Mouse::getScore() const
{
	return m_score;
}

void Mouse::addSouls(int soulNum)
{
	m_life += soulNum;
}

void Mouse::move(sf::Vector2i direction, float deltaTime)
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
	this->getSprite()->move((-1) * intersection.width * this->getDirection().x,
		(-1) * intersection.height * this->getDirection().y);
}

void Mouse::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void Mouse::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
	this->m_sounds->playKeySound();
	this->addKey();
}

void Mouse::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
	this->getSprite()->move((-1) * intersection.width * this->getDirection().x,
		(-1) * intersection.height * this->getDirection().y);
}

void Mouse::handleKeys(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->move(LEFT, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->move(RIGHT, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->move(UP, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->move(DOWN, deltaTime);
	}
}


