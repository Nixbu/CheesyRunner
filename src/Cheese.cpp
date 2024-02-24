#pragma once 

#include "Cheese.h"

int Cheese::m_count = 0;

Cheese::Cheese(sf::Vector2f position, sf::Texture* texture,
	sf::SoundBuffer * soundBffr) :
	StaticObject(position , texture, soundBffr) 
{
	m_count++;
}

Cheese::~Cheese()
{
	m_count--;
}

 int Cheese::getCount()
{
	return m_count;
}

void Cheese::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	
}

void Cheese::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
	gameObject.handleCollision(*this, intersection);
}

void Cheese::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}

void Cheese::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}

void Cheese::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void Cheese::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}

void Cheese::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}

