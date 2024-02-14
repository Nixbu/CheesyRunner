#pragma once

#include "MovingObject.h"

class Mouse :public MovingObject {
public:
	Mouse(sf::vector2f pos, sf::Texture* texture);
	~Mouse() = default;
	void setKeys(int keys);
	void setCheese(int cheese);
	int getCheese() const;
	int getKeys() const;
	void move() override;
	void draw() const override;
private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;

};