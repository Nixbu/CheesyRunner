#include "GameManager.h"

GameManager::GameManager()
	: m_textures(), m_menu(m_textures)
{
}

void GameManager::run()
{
	sf::Vector2f mousePos;

	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Mouse And Cat");

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.clear();

		m_menu.draw(&window);

		window.display();


		for (auto event = sf::Event{}; window.pollEvent(event); ) 
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
				break;

			case sf::Event::MouseButtonReleased:

				mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				m_menu.handleClicks(mousePos, &window, m_textures);
				break;

			/*case sf::Event::MouseMoved:

				sf::Event::MouseMoveEvent mouse = event.mouseMove;
				mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
				m_menu.handleFloating(mousePos);*/
			}
		}


	}
}
