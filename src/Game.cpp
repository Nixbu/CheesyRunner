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
	sf::RenderWindow * window)
	: m_player(sf::Vector2f(0, 0), textures->getTexture(mouseTexture), MOUSE_VELOCITY),
	m_window(window)
{
	m_textures = textures;
	std::ifstream playlistLevelFile;

	m_playlist.open("LevelPlaylistFile.txt");
	/*checkFile(playlistLevelFile);*/
	
}

void Game::run()
{
	std::ifstream levelFile;
	std::string levelName;
	
	
	while (std::getline(m_playlist, levelName))
	{
		std::cout << levelName;
		levelFile.open(levelName);
		/*checkFile(levelFile);*/
		Level currentLevel( m_textures , &m_player);
		currentLevel.levelLoop(m_window , &levelFile);
		if (!m_window->isOpen())
		{
			levelFile.close();
			break;
		}
		levelFile.close();

	}
}

