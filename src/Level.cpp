#include "Level.h"

Level::Level( TextureManager* textures, Mouse* player)
	:  m_board() 
{
	m_player = player;
	m_textures = textures;
}

void Level::levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile)
{
	m_board.readBoard(levelFile, m_player, m_cats , m_textures);

	window->create(sf::VideoMode(this->m_board.getWidth(),
		this->m_board.getHeight()),
		"Mouse And Cat");
	while (window->isOpen())
	{
		window->clear();

		this->draw(window);
		
		window->display();

		this->handleEvents(window);

		this->m_player->handleKeys(m_clock.restart().asSeconds());

		this->handleAllCollisions();
		
	}
}

void Level::handleEvents(sf::RenderWindow * window)
{
	for (auto event = sf::Event{}; window->pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:

			window->close();
			break;
		}
	}
}



void Level::handleAllCollisions()
{
	sf::FloatRect intersection;


	for (int object = 0; object < m_board.getObstacles().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getObstacles()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getObstacles()[object]->handleCollision(*m_player, intersection);
		}
	}

	for (int object = 0; object < m_board.getGameObjects().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getGameObjects()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getGameObjects()[object]->handleCollision(*m_player, intersection);

			this->m_board.removeObject(object);
		}
	}

}

void Level::draw(sf::RenderWindow* window)
{
	this->m_board.draw(window);
	
	for (int idx = 0; idx < m_cats.size(); idx++)
	{
		m_cats[idx]->draw(window);
	}
	
	this->m_player->draw(window);
}