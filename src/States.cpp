#include "States.h"

States::States(Mouse* mouse, TextureManager* textures)
	: m_levelTime(DEFAULT_TIME), m_position(sf::Vector2f(0, 0)), m_clock()
{
	m_mouse = mouse;
	m_textures = textures;

	m_font.loadFromFile("StatesFont.ttf");

	this->setText(m_scoreText);
	this->setText(m_timeText);
	
	for (int heart = 0; heart < m_mouse->getSouls(); heart++)
	{
		m_hearts.push_back(std::make_unique<Heart>(sf::Vector2f(0, 0),
			textures->getTexture(heartTexture)));
	}
}

void States::setLevelState(float boardHeight, float levelTime)
{
	this->m_levelTime = levelTime;
	this->m_position.y = boardHeight;
	this->m_clock.restart();

	sf::Vector2f currentPos = { 20   , boardHeight }; // can use offset};

	for (int heart = 0; heart < STARTING_SOULS; heart++)
	{
		m_hearts[heart] ->setPosition(currentPos);
		currentPos.x += HEART_OFFSET;
		
	}

	this->m_scoreText.setPosition(currentPos);
	currentPos.x += SCORE_OFFSET;
	this->m_timeText.setPosition(currentPos);
}


void States::draw(sf::RenderWindow* window)
{
	for (int heart = 0; heart < m_mouse->getSouls(); heart++)
	{
		m_hearts[heart] ->draw(window);
	}

	m_timeText.setString("Time: " + std::to_string(m_levelTime - m_clock.getElapsedTime().asSeconds()));

	m_scoreText.setString("Score: " + std::to_string(m_mouse->getScore()));

	window->draw(m_timeText);
	window->draw(m_scoreText);
}

void States::setText(sf::Text& text)
{
	text.setFont(m_font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Yellow);
}
