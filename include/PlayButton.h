#pragma once

#include "Button.h"
#include "Game.h"


class PlayButton : public Button{
public:
	using Button::Button;
	~PlayButton() = default;
	
	virtual void action(sf::RenderWindow* window, const TextureManager& textures) override;

private:
};