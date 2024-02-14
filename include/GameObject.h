#pragma once

#include <SFML/Graphics.hpp>


class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Texture * texture);
	virtual ~GameObject() = default;
	
	const sf::Sprite* getSprite() const;
	void scale(const sf::Vector2f &values);
	void setPos(const sf::Vector2f &newPos);

	virtual void draw(sf::RenderWindow * window) const = 0;

	
private:
	sf::Sprite m_sprite;
};