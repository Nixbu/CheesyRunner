#pragma once

#include "MovingObject.h"

#include "Mouse.h";
#include <iostream>

class Cat : public MovingObject {
public:
	Cat(sf::Vector2f position, sf::Texture* texture,
		float velocity, Mouse* mouse);
	~Cat() = default;
	void move(float deltaTime, 
		std::vector<std::vector<bool>> boardMatrix);
	void draw(sf::RenderWindow* window) const override;
	sf::Vector2f dfsChasingAlgorithm(std::vector<std::vector<bool>> boardMatrix) const;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
private:
	Mouse* m_player;
};