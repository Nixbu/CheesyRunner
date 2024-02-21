#include "Level.h"

Level::Level( TextureManager* textures, Mouse* player)
	:  m_board() , m_level_time(DEFAULT_TIME), m_states(player, textures)
{
	m_player = player;
	m_textures = textures;
}

void Level::levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile)
{
	m_board.readBoard(levelFile, m_player, m_cats , m_textures , m_level_time);
	std::cout << "Out of readboard";

	m_states.setLevelState(this->m_board.getHeight(), m_level_time);

	window->create(sf::VideoMode(this->m_board.getWidth(),
		this->m_board.getHeight() + 100),
		"Mouse And Cat");
	while (window->isOpen() && Cheese::getCount() != 0)
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
	bool key;


	for (int object = 0; object < m_board.getWalls().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getWalls()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getWalls()[object]->handleCollision(*m_player, intersection);
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
	this->m_states.draw(window);
}