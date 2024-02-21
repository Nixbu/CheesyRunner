#include "Board.h"

Board::Board() :
	m_width(0), m_length(0)
{
}

void Board::readBoard(std::ifstream * levelFile , Mouse * mouse ,
	std::vector<std::unique_ptr<Cat>>& cats ,
				const TextureManager * textures ,
				float &leveltime)
{
	*levelFile >> leveltime;

	std::string line;
	sf::Vector2i pos = { 0 , 0 };
	sf::Vector2f  currLocation;

	//reading line
	while (std::getline(*levelFile, line))
	{
		// checks which objects were in the line
		for (pos.x = 0; pos.x < line.length(); pos.x++)
		{
			 m_width = (float)line.length() * TILE_WIDTH;
			 currLocation ={ TILE_WIDTH * pos.x,  pos.y * TILE_LENGTH };
				
		
			switch (line[pos.x])
			{
			case '%':
				//updating mouse states as needed
				mouse->setPos(currLocation);
				mouse->setKeys((- 1)* mouse ->getKeys());
				mouse->setCheese((-1) * mouse->getCheese());
				break;
			case '^':
				cats.push_back(std::make_unique<Cat>(currLocation,
					textures->getTexture(catTexture), CAT_VELOCITY));
				break;

			case '*': 
				m_gameObjects.push_back(std::make_unique<Cheese>(currLocation ,
							textures->getTexture(cheeseTexture)));
				break;
			case 'D':
				m_obstacles.push_back(std::make_unique<Door>(currLocation,
					textures->getTexture(doorTexture)));
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(currLocation,
					textures->getTexture(keyTexture)));
				break;
			/*case '$':
				m_gameObjects.push_back(std::make_unique<Gift>(currLocation,
					textures.getTexture(giftTexture)));
				break;*/
			case '#':
				m_obstacles.push_back(std::make_unique<Wall>(currLocation,
					textures->getTexture(wallTexture)));
				break;
			default:
				break;
			}

			m_bgTiles.push_back(std::make_unique<BackgroundTile>(currLocation,
				textures->getTexture(bgTileTexture)));
		}

		pos.y++;

	}
	m_length = pos.y * TILE_LENGTH;

	levelFile->clear();
}

void Board::removeObject(int index)
{
	m_gameObjects.erase(m_gameObjects.begin() + index);
}

void Board::draw(sf::RenderWindow * window)
{
	for (int idx = 0; idx < m_bgTiles.size(); idx++)
	{
		m_bgTiles[idx]->draw(window);
	}


	for (int idx = 0; idx < m_obstacles.size(); idx++)
	{
		m_obstacles[idx]->draw(window);
	}


	for (int idx = 0; idx < m_gameObjects.size(); idx++)
	{
		m_gameObjects[idx]->draw(window);
	}

	
}

const std::vector<std::unique_ptr<GameObject>>& Board::getObstacles() const
{
	return m_obstacles;
}

const std::vector<std::unique_ptr<GameObject>>& Board::getGameObjects() const
{
	return m_gameObjects;
}

float Board::getWidth() const
{
	return m_width;
}

float Board::getHeight() const
{
	return m_length;
}
