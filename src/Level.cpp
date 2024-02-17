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
	while (window->isOpen())
	{
		window->clear();

		this->m_board.draw(window);
		

		window->display();

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
}
