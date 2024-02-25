#pragma once

#include "TextureManager.h"
#include <vector>
#include "Button.h"
#include "Menu.h"
#include <SFML/Audio.hpp>
#include "SoundManager.h"

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
