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
	
	
	while (std::getline(m_playlist, levelName))
	{

		levelFile.open(levelName);
		/*checkFile(levelFile);*/
		Level currentLevel( m_textures , m_sounds, &m_player);
		currentLevel.levelLoop(m_window , &levelFile);
		if (!m_window->isOpen() || this ->m_player.getSouls() <= 0)
		{
			levelFile.close();
			break;
		}
		levelFile.close();

	}
}

