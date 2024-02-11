#pragma once

#include <SFML/Graphics.hpp>


class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Texture * texture);
	virtual ~GameObject() = default;

	virtual void draw() = 0;
private:
	sf::Sprite m_sprite;
};