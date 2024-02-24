#pragma once

#include "Button.h"

class ExitButton : public Button {
public:
	using Button::Button;

	virtual void action(sf::RenderWindow* window, const TextureManager& textures,
		const SoundManager& sounds) override;

private:
};