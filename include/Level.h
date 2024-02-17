#pragma once

#include "Board.h"
#include <vector>
#include "Cat.h"
#include "Mouse.h"
#include <fstream>
#include "TextureManager.h"
#include <SFML/Graphics.hpp>


class Level {
public:
	Level(TextureManager* textures,
		Mouse* player);
		
	virtual ~Level() = default;

	void levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile);
	void draw(sf::RenderWindow* window);



private:
	Board m_board;
	sf::Clock m_clock;
	sf::Clock * m_timer;
	/*int m_level_time*/
	std::vector<std::unique_ptr<Cat>>  m_cats;
	TextureManager* m_textures;
	Mouse* m_player;

	
};
