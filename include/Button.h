#pragma once

#include "GameObject.h"
#include "Settings.h"

class Button: public GameObject {

public:
	Button(sf::Vector2f position, sf::Texture* texture);
	virtual ~Button() = default;
	bool isClicked(sf::Vector2f mousePosition) const;
	virtual void draw(sf::RenderWindow* window) const override;
	
private:
};
