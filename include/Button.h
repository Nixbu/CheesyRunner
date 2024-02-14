#pragma once

#include "GameObject.h"
#include "Settings.h"
#include "Game.h"

class Button {

public:
	Button(sf::Vector2f position, sf::Texture* texture);
	virtual ~Button() = default;
	
	const sf::Sprite* getSprite() const;
	void scale(const sf::Vector2f& values);
	void setPos(const sf::Vector2f& newPos);
	bool isClicked(sf::Vector2f mousePosition) const;
	virtual void draw(sf::RenderWindow* window) const;
	virtual void action(Game& game);

private:
	sf::Sprite m_sprite;
};
