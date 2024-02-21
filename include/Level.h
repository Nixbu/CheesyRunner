#pragma once

#include "Board.h"
#include <vector>
#include "Cat.h"
#include "Mouse.h"
#include <fstream>
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "States.h"


class Level {
public:
	Level(TextureManager* textures,
		Mouse* player);
		
	virtual ~Level() = default;

	void levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile);
	void draw(sf::RenderWindow* window);
	void handleEvents(sf::RenderWindow* window);
	void handleKeys(float deltaTime);
	void handleAllCollisions();


private:
	Board m_board;
	sf::Clock m_clock;
	sf::Clock * m_timer;
	float m_level_time;
	std::vector<std::unique_ptr<Cat>> m_cats;
	TextureManager* m_textures;
	Mouse* m_player;
	States m_states;

	
};
