#include "States.h"

States::States(Mouse* mouse, TextureManager* textures)
	: m_levelTime(DEFAULT_TIME), m_position(sf::Vector2f(0, 0)), m_clock()
{
	m_mouse = mouse;
	m_textures = textures;

	m_font.loadFromFile("StatesFont.ttf");

	this->setText(m_scoreText);
	this->setText(m_timeText);
	this->setText(m_keyText);
	
	for (int heart = 0; heart < STARTING_SOULS; heart++)
	{
		m_hearts.push_back(std::make_unique<Heart>(sf::Vector2f(0, 0),
			textures->getTexture(heartTexture)));
	}
}

void States::setLevelState(float boardHeight, int levelTime)
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
	currentPos.x += TIME_OFFSET;
	this->m_keyText.setPosition(currentPos);
}


void States::draw(sf::RenderWindow* window)
{
	for (int heart = 0; heart < m_mouse->getSouls(); heart++)
	{
		m_hearts[heart] ->draw(window);
	}

	m_timeText.setString("Time: " + std::to_string(m_levelTime -(int)m_clock.getElapsedTime().asSeconds()));

	m_scoreText.setString("Score: " + std::to_string(m_mouse->getScore()));
	
	m_keyText.setString("Keys: " + std::to_string(m_mouse->getKeys()));

	window->draw(m_timeText);
	window->draw(m_scoreText);
	window->draw(m_keyText);
	
}

void States::setLevelTime(int time)
{
	m_levelTime = time;
}

int States::getTimeAsSeconds() const
{
	return m_clock.getElapsedTime().asSeconds();
}

void States::setText(sf::Text& text)
{
	text.setFont(m_font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Yellow);
}
