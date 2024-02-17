#include "Level.h"

Level::Level(std::ifstream* levelFile, TextureManager* textures, Mouse* player)
	: m_board(levelFile, player, &m_cats, *textures)
{
}

void Level::levelLoop(sf::RenderWindow * window)
{

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
