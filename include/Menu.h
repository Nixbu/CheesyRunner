#pragma once

#include "Button.h"
#include "Settings.h"
#include <vector>
#include <memory>
#include "TextureManager.h"
#include "SoundManager.h"
#include "PlayButton.h"
#include "HelpButton.h"
#include "ExitButton.h"

/*
	Class Menu:
		The class holds the button of the prime menu.
*/

class Menu {
public:
	Menu(const TextureManager & textures);
	virtual ~Menu();

	Button * getButton(Button_t btn) const;
	void draw(sf::RenderWindow* window) const;
	void handleClicks(sf::Vector2f mousePos,
		sf::RenderWindow* window,
		const TextureManager& textures,
		const SoundManager& sounds);
	void handleFloating(sf::Vector2f mousePos);

private:
	std::vector<Button *> m_buttons;
	sf::Sprite m_backgroung_img;
};