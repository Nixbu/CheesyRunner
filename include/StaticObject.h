#pragma once

#include "GameObject.h"
#include "SFML/Audio.hpp"

class StaticObject : public GameObject
{
public:
	StaticObject(sf::Vector2f position, sf::Texture* texture,
		sf::SoundBuffer* soundBffr);
	virtual ~StaticObject() = default;

	virtual void draw(sf::RenderWindow* window) const;
	void playSound();

private:
	sf::Sound m_sound;
};