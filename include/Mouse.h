#pragma once

#include "MovingObject.h"
#include "Settings.h"

class Mouse :public MovingObject {
public:
	Mouse(sf::Vector2f position, sf::Texture* texture,
		float velocity);
	~Mouse() = default;
	void setKeys(int keys);
	void setCheese(int cheese);
	int getCheese() const;
	int getKeys() const;
	int getSouls() const;
	void move(sf::Vector2f direction, float deltaTime);
	void draw(sf::RenderWindow * window) const override;

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);


private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;

};