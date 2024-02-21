#include "States.h"

States::States(Mouse* mouse, TextureManager* textures)
	: m_levelTime(DEFAULT_TIME), m_position(sf::Vector2f(0, 0)), m_clock()
{
	m_mouse = mouse;
	m_textures = textures;
	
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

	sf::Vector2f current_pos = { 20   , boardHeight }; // can use offset};

	for (int heart = 0; heart < STARTING_SOULS; heart++)
	{
		m_hearts[heart] ->setPosition(current_pos);
		current_pos.x += HEART_OFFSET;
		
	}
}


void States::draw(sf::RenderWindow* window)
{
	for (int heart = 0; heart < m_mouse->getSouls(); heart++)
	{
		m_hearts[heart] ->draw(window);
	}
}
