#pragma once

#include "TextureManager.h"
#include <vector>
#include "Button.h"
#include "Menu.h"
#include <SFML/Audio.hpp>
#include "SoundManager.h"

/*
	Class GameManager:
		The class manages everything in the program:
			The main window with the menu,
			the textures, the sounds and the game
*/

class GameManager {
public:
	GameManager();
	virtual ~GameManager() = default;
	void run();

private:
	TextureManager m_textures;
	Menu m_menu;
	SoundManager m_sounds;
	sf::Music m_music;

	void loadMusic();
};
