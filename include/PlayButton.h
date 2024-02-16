#pragma once

#include "Button.h"
#include "Game.h"


class PlayButton : public Button{
public:
	using Button::Button;
	
	virtual void action(sf::RenderWindow* window) override;

private:
};