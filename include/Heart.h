#pragma once

#include <SFML/Graphics.hpp>


/*
	Class Heart:
		The class represents the represents the heart shown in States.
*/

class Heart {
public:
	Heart(sf::Vector2f position, sf::Texture * texture);
	virtual ~Heart() = default;
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow * window);
private:
	sf::Sprite m_sprite;
};