#include "Heart.h"


//======================================================
//ctor
Heart::Heart(sf::Vector2f position, sf::Texture* texture) 
	
{
	m_sprite.setTexture(*texture);
	m_sprite.setPosition(position);

}
//======================================================
void Heart::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}
//======================================================
void Heart::draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}
