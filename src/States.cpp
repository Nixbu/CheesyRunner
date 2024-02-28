#include "States.h"

// ctor
States::States(Mouse* mouse, TextureManager* textures)
	: m_levelTime(DEFAULT_TIME), m_position(sf::Vector2f(0, 0)), m_clock() ,
	m_levelNum(0) 
{
	m_mouse = mouse;
	m_textures = textures;

	m_font.loadFromFile("StatesFont.ttf");

	// setting the wanted texts
	this->setText(m_scoreText);
	this->setText(m_timeText);
	this->setText(m_keyText);
	this->setText(m_levelText);
	this->setText(m_timerText);

	this->m_clockSprite.setTexture(*(textures->getTexture(clockTexture)));
	
	for (int heart = 0; heart < STARTING_SOULS; heart++)
	{
		m_hearts.push_back(std::make_unique<Heart>(sf::Vector2f(0, 0),
			textures->getTexture(heartTexture)));
	}
}
//======================================================
// function updates the states according to the current level
void States::setLevelState(const float& boardHeight, const int &levelTime , const int &leveNum)
{
	this->m_levelTime = levelTime;
	this->m_position.y = boardHeight;
	this->m_levelNum = leveNum;
	this->m_clock.restart();

	sf::Vector2f PosStates = { 20   , boardHeight } ,
		PosLevelAndTime = { 20  , boardHeight + 35 }; 

	for (int heart = 0; heart < STARTING_SOULS; heart++)
	{
		m_hearts[heart] ->setPosition(PosStates);
		PosStates.x += HEART_OFFSET;
		
	}
	//  level time text , clock and keys
	this->m_scoreText.setPosition(PosStates);
	PosStates.x += SCORE_OFFSET;
	this->m_timeText.setPosition(PosStates);
	PosStates.x += TIME_OFFSET;
	this->m_keyText.setPosition(PosStates);

	// clock , level timer
	m_clockSprite.setPosition(PosLevelAndTime);
	PosLevelAndTime.x += TIMER_OFFSET;
	this->m_timerText.setPosition(PosLevelAndTime);
	PosLevelAndTime.x = LEVEL_AND_TIME_OFFSET;
	this->m_levelText.setPosition(PosLevelAndTime);
}

//======================================================
// function draws the state section
void States::draw(sf::RenderWindow* window)
{
	for (int heart = 0; heart < m_mouse->getSouls(); heart++)
	{
		m_hearts[heart] ->draw(window);
	}

	m_timeText.setString("Time: " + std::to_string((int)m_clock.getElapsedTime().asSeconds()));

	m_scoreText.setString("Score: " + std::to_string(m_mouse->getScore()));
	
	m_keyText.setString("Keys: " + std::to_string(m_mouse->getKeys()));

	m_levelText.setString("Level: " + std::to_string(m_levelNum));

	if (m_levelTime != NO_TIME)
	{
		m_timerText.setString(std::to_string(m_levelTime - (int)(m_clock.getElapsedTime().asSeconds())));
	}
	else
	{
		m_timerText.setString("**");
	}
	

	window->draw(m_timeText);
	window->draw(m_scoreText);
	window->draw(m_keyText);
	window->draw(m_levelText);
	window->draw(m_timerText);
	window->draw(m_clockSprite);
}
//======================================================
void States::setLevelTime(int time)
{
	m_levelTime = time;
}
//======================================================
int States::getTimeAsSeconds() const
{
	return m_clock.getElapsedTime().asSeconds();
}
//======================================================
void States::setText(sf::Text& text)
{
	text.setFont(m_font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Yellow);
}
