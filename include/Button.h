#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SoundManager.h"

/*
	Class Button:
		The class represents a clickable button to be used for the UI.
		The class is abstract.
*/

class Button {

public:
	Button(sf::Vector2f position, sf::Texture* texture);
	virtual ~Button() = default;
	
	const sf::Sprite* getSprite() const;
	void scale(const sf::Vector2f& values);
	void setPos(const sf::Vector2f& newPos);
	bool isClicked(sf::Vector2f mousePosition) const;
	virtual void draw(sf::RenderWindow* window) const;
	virtual void action(sf::RenderWindow* window, 
		const TextureManager& textures,
		const SoundManager& sounds) = 0;
	/*void resize(sf::Vector2f wantedSize);*/

private:
	sf::Sprite m_sprite;
};
