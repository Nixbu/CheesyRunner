#pragma once

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include <vector>
#include "TextureManager.h"
#include "Heart.h"
#include "Settings.h"

class States {
public:
	States(Mouse* mouse, TextureManager* textures);

	void setLevelState(float boardHeight, float levelTime);

	void draw(sf::RenderWindow* window);

private:
	Mouse* m_mouse;
	TextureManager* m_textures;
	sf::Vector2f m_position;

	sf::Clock m_clock;
	float m_levelTime;
	std::vector<std::unique_ptr<Heart>> m_hearts;
};