#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"

class Cat;
class Cheese;
class Wall;
class Door;
class Mouse;
class Key;
class Gift;
class Wall;

class GameObject {
public:
	GameObject(sf::Vector2f position, sf::Texture * texture);
	virtual ~GameObject() = default;
	
	 sf::Sprite* getSprite() const;
	void scale(const sf::Vector2f &values);
	void setPos(const sf::Vector2f &newPos);

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection) = 0;
    virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection) = 0;
    virtual void handleCollision(Cheese& gameObject , sf::FloatRect intersection) = 0;
    virtual void handleCollision(Door& gameObject, sf::FloatRect intersection) = 0;
    virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection) = 0;
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection) = 0;
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection) = 0;


	/*virtual void handleCollision(Gift& gameObject) = 0;*/


	virtual void draw(sf::RenderWindow * window) const = 0;

	
private:
	sf::Sprite m_sprite;
};