#pragma once

#include <SFML/Graphics.hpp>


class Heart {
public:
	Heart(sf::Vector2f position, sf::Texture * texture);
	virtual ~Heart() = default;
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow * window);
private:
	sf::Sprite m_sprite;
};