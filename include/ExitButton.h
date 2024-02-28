#pragma once

#include "Button.h"

/*
	Class ExitButton:
		The class represents the exit button in the UI.
		Inherits from Button.h.
*/

class ExitButton : public Button {
public:
	using Button::Button;

	virtual void action(sf::RenderWindow* window, const TextureManager& textures,
		const SoundManager& sounds) override;

private:
};