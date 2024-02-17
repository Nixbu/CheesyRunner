#pragma once

#include "MovingObject.h"
#include "Settings.h"

class Mouse :public MovingObject {
public:
	Mouse(sf::Vector2f pos, sf::Texture* texture);
	~Mouse() = default;
	void setKeys(int keys);
	void setCheese(int cheese);
	int getCheese() const;
	int getKeys() const;
	void move(sf::Vector2f direction, sf::Time deltaTime);
	void draw(sf::RenderWindow * window) const override;

private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;

	void setDirection(sf::Vector2f direction);

};