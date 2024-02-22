#include "Board.h"

Board::Board() :
	m_width(0), m_length(0)
{
}

void Board::readBoard(std::ifstream * levelFile , Mouse * mouse ,
	std::vector<std::unique_ptr<Cat>>& cats ,
				const TextureManager * textures ,
				int &leveltime)
{
	*levelFile >> leveltime;

	int  numOfGifts = 0;
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
				m_doors.push_back(std::make_unique<Door>(currLocation,
					textures->getTexture(doorTexture)));
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(currLocation,
					textures->getTexture(keyTexture)));
				break;
			case '$':
				numOfGifts++;
				genarateGift(numOfGifts , currLocation , textures);
				break;
			case '#':
				m_walls.push_back(std::make_unique<Wall>(currLocation,
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
	//instead set seek to 0 , 0 if player got crashed.
	levelFile->clear();
}

void Board::genarateGift(int numOfGifts , sf::Vector2f location , const TextureManager * textures)
{
	static bool isKillCat = false; // i want to give only once the kill cat gift
								  // and only if the level is hard
	int giftType;

	if (numOfGifts > NUM_OF_GIFTS_FOR_EZ_LEVEL && !isKillCat)
	{
		m_gifts.push_back(std::make_unique<KillCatGift>(location,
			textures->getTexture(giftTexture)));

		isKillCat = true;

		return;
	}
	else
	{
		giftType =  rand() % GIFT_TYPES;

		switch (giftType)
		{
		case freeze:
			m_gifts.push_back(std::make_unique<FreezeGift>(location,
				textures->getTexture(giftTexture)));
			
			break;
		case addTime:
			m_gifts.push_back(std::make_unique<TimeGift>(location,
				textures->getTexture(giftTexture)));
			break;
		default:
			break;
		}
	}
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


	for (int idx = 0; idx < m_walls.size(); idx++)
	{
		m_walls[idx]->draw(window);
	}

	for (int idx = 0; idx < m_doors.size(); idx++)
	{
		m_doors[idx]->draw(window);
	}


	for (int idx = 0; idx < m_gameObjects.size(); idx++)
	{
		m_gameObjects[idx]->draw(window);
	}
	
	for (int idx = 0; idx < m_gifts.size(); idx++)
	{
		m_gifts[idx]->draw(window);
	}

	
}

const std::vector<std::unique_ptr<Wall>>& Board::getWalls() const
{
	return m_walls;
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
