#include "Game.h"

////====================================================================
//void checkFile(std::ifstream& file)
//{
//	if (!file.is_open())
//	{
//		std::cerr << "Error opening file\n";
//		exit(EXIT_FAILURE);
//	}
//}


Game::Game(TextureManager * textures,
	SoundManager * sounds,
	sf::RenderWindow * window)
	: m_player(sf::Vector2f(0, 0),
		textures->getTexture(mouseFrontTexture),
		MOUSE_VELOCITY,
		sounds,
		textures),
	m_window(window)
{
	m_textures = textures;
	m_sounds = sounds;
	std::ifstream playlistLevelFile;

	m_playlist.open("LevelPlaylistFile.txt");
	/*checkFile(playlistLevelFile);*/
	
}

void Game::run()
{
	std::ifstream levelFile;
	std::string levelName;
	bool passed = false , exit = false;
	int levelNum = 0;
	
	
	while (std::getline(m_playlist, levelName))
	{
		passed = false;
		levelNum ++;
		levelFile.open(levelName);
		/*checkFile(levelFile);*/

		while (!passed && this->m_player.getSouls() > 0 && m_window->isOpen())
		{
			Level currentLevel(m_textures, m_sounds, &m_player);
			currentLevel.levelLoop(m_window, &levelFile , passed , levelNum , exit);			
		}

		if (!m_window->isOpen() || this->m_player.getSouls() <= 0)
		{
			levelFile.close();
			break;
		}
		levelFile.close();


	}
	if (!exit)
	{
		displayResultScreen(passed);
	}
	
}

void Game::displayResultScreen(const bool& passed)
{
	sf::Clock clock;

	sf::Sprite endScrean;

	if (passed)
	{
		endScrean.setTexture(*m_textures->getTexture(youWonTexture));
	}
	else
	{
		endScrean.setTexture(*m_textures->getTexture(youLostTexture));
	}

	endScrean.setPosition({ 0, 0 });

	m_window->create(sf::VideoMode(WINDOW_MANAGER_WIDTH, WINDOW_MANAGER_HEIGHT),
		"Mouse And Cat");

	float timer = clock.getElapsedTime().asSeconds() + DISPLAY_TIME;
	while (timer > clock.getElapsedTime().asSeconds())
	{
		m_window->clear();

		m_window->draw(endScrean);

		m_window->display();
	}
	
}

