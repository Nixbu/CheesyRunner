#include "StaticObject.h"

StaticObject::StaticObject(sf::Vector2f position, sf::Texture* texture,
	sf::SoundBuffer * soundBffr) :
	GameObject(position, texture)
{
	this->scale(sf::Vector2f(0.33, 0.33));
	m_sound.setBuffer(*soundBffr);
}

void StaticObject::draw(sf::RenderWindow* window) const
{
	window->draw(*this->getSprite());
}

void StaticObject::playSound()
{
	m_sound.play();
}
