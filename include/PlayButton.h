#pragma once

#include "Button.h"
#include "Game.h"

/*
	Class PlayButton:
		The class represents a button in the prime menu.
*/


class PlayButton : public Button{
public:
	using Button::Button;
	~PlayButton() = default;
	
	virtual void action(sf::RenderWindow* window, const TextureManager& textures,
		const SoundManager& sounds) override;

private:
};