#pragma once

#include "GameObject.h"



const float BUTTON_SCALE = 2.0; 


class Button: public GameObject {

public:
	Button(sf::Vector2f position, sf::Texture* texture);
	bool isClicked(sf::Vector2f mousePosition) const;
	virtual ~Button() = default;
private:

};
