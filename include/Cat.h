#pragma once

#include "MovingObject.h"
#include "TextureManager.h"
#include "Mouse.h"
#include <iostream>

/*
	Class Cat:
		The class represents the cat enemy in the game.
*/

class Cat : public MovingObject {
public:
	Cat(sf::Vector2f position, sf::Texture* texture,
		float velocity, Mouse* mouse,
		const TextureManager * textures);
	~Cat() = default;

	sf::Vector2i chooseMove(std::vector<std::vector<int>> boardMatrix) const;
	void move(float deltaTime,
		std::vector<std::vector<int>> boardMatrix);

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
private:
	Mouse* m_player;
	const TextureManager* m_textures;
	sf::Vector2i findMinDirection(int upDistance, int downDistance,
		int rightDistance, int leftDistance) const;

	void setSpriteDirection(sf::Vector2i direction);
};