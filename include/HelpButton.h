#pragma once

#include "Button.h"
/*
	Class HelpButton:
		The class represents the help button in the prime menu.
*/
class HelpButton : public Button {
public:
	using Button::Button;

	virtual void action(sf::RenderWindow* window, const TextureManager& textures,
		const SoundManager& sounds) override;

private:

	void handleEvents(sf::RenderWindow* window);
};