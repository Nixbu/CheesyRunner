#pragma once

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include <vector>
#include "TextureManager.h"
#include "Heart.h"
#include "Settings.h"

/*
	Class States:
		The class represents the data line in the game ( life ,keys , time).
*/

class States {
public:
	States(Mouse* mouse, TextureManager* textures);

	void setLevelState(const float& boardHeight, const int& levelTime, const int& leveNum);

	void draw(sf::RenderWindow* window);
	void setLevelTime(int time);
	int getTimeAsSeconds() const;

private:
	Mouse* m_mouse;
	TextureManager* m_textures;
	sf::Vector2f m_position;

	sf::Clock m_clock;
	int m_levelTime, m_levelNum;
	std::vector<std::unique_ptr<Heart>> m_hearts;
	sf::Font m_font;
	sf::Text m_scoreText,
		m_timeText,
		m_keyText,
		m_levelText,
		m_timerText;
	sf::Sprite m_clockSprite;

	void setText(sf::Text& text);

};