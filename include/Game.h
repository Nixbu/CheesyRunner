#pragma once

#include "TextureManager.h"
#include "SoundManager.h"
#include "Mouse.h"
#include "Level.h"
//#include "Utilities.h"
#include <fstream>
#include <string>

class Game {
public:
	Game(TextureManager * textures,
		SoundManager* sounds,
		sf::RenderWindow * window);
	virtual ~Game() = default;

	void run();

private:
	Mouse m_player;
	std::ifstream m_playlist;
	sf::RenderWindow * m_window;
	TextureManager * m_textures;
	SoundManager* m_sounds;

};