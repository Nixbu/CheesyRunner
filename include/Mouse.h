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
	void move(sf::Vector2f direction, float deltaTime);
	void draw(sf::RenderWindow * window) const override;

private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;

};