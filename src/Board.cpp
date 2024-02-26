#include "Board.h"

Board::Board() :
	m_width(0), m_length(0)
{
}

void Board::readBoard(std::ifstream * levelFile , Mouse * mouse ,
	std::vector<std::unique_ptr<Cat>>& cats ,
				const TextureManager * textures ,
				int &leveltime,
	std::vector<std::vector<int>> & boardMatrix)
{
	*levelFile >> leveltime;
	levelFile->get();

	int  numOfGifts = 0;
	std::string line;
	sf::Vector2i pos = { 0 , 0 };
	sf::Vector2f  currLocation;
	
	int tileState;

	//reading line
	while (std::getline(*levelFile, line))
	{
		std::vector<int> currentLine;
		// checks which objects were in the line
		for (pos.x = 0; pos.x < line.length(); pos.x++)
		{
			tileState = VALID;
			m_width = (float)line.length() * TILE_WIDTH;
			currLocation ={ TILE_WIDTH * pos.x,  pos.y * TILE_LENGTH };
				
		
			switch (line[pos.x])
			{
			case '%':
				//updating mouse states as needed
				mouse->setPos(currLocation);
				mouse->setKeys(0);
				mouse->setCheese((-1) * mouse->getCheese());
				mouse->getSprite()->setTexture(*textures->getTexture(mouseFrontTexture));
				mouse->setInitPos(currLocation);
				break;
			case '^':
				cats.push_back(std::make_unique<Cat>(currLocation + CAT_OFFSET,
					textures->getTexture(catFrontTexture), CAT_VELOCITY, mouse,
					textures));
				break;

			case '*': 
				m_gameObjects.push_back(std::make_unique<Cheese>(currLocation ,
							textures->getTexture(cheeseTexture)));
				break;
			case 'D':
				m_doors.push_back(std::make_unique<Door>(currLocation,
					textures->getTexture(doorTexture)));
				tileState = INFINIT;
				break;
			case 'F':
				m_gameObjects.push_back(std::make_unique<Key>(currLocation,
					textures->getTexture(keyTexture)));
				break;
			case '$':
				numOfGifts++;
				genarateGift(numOfGifts , currLocation , textures , leveltime);
				break;
			case '#':
				m_walls.push_back(std::make_unique<Wall>(currLocation,
					textures->getTexture(wallTexture)));
				tileState = INFINIT;
				break;
			default:
				break;
			}
			
			m_bgTiles.push_back(std::make_unique<BackgroundTile>(currLocation,
				textures->getTexture(chooseRandTexture()))); // Get a unique bg tile each time
			currentLine.push_back(tileState);
		}
		boardMatrix.push_back(currentLine);
		pos.y++;

	}
	m_length = pos.y * TILE_LENGTH;
	//instead set seek to 0 , 0 if player got crashed.
	levelFile->clear();
	levelFile ->seekg(0, std::ios::beg);
}

Texture_t Board::chooseRandTexture()
{
	int rndVal = rand() % BG_TILES,
		chosen = BASE_TILE + rndVal;
	

	switch (chosen)
	{
	case bgTileTexture:
		return bgTileTexture;

	case bgTileTexture2:
		return bgTileTexture2;

	case bgTileTexture3:
		return bgTileTexture3;

	case bgTileTexture4:
		return bgTileTexture4;

	case bgTileTexture5:
		return bgTileTexture5;

	default:
		break;
	}

}


void Board::genarateGift(int numOfGifts , sf::Vector2f location ,
	const TextureManager * textures , const int& levelTime)
{

	int giftType;

	if (numOfGifts == KILL_CAT_GIFT)
	{
		m_gifts.push_back(std::make_unique<KillCatGift>(location,
			textures->getTexture(deadCatGiftTexture)));
		return;
	}
	else
	{
		if (levelTime == NO_TIME)
		{
			giftType = rand() % (GIFT_TYPES -1);
		}
		else
		{
			giftType = rand() % GIFT_TYPES;
		}

		switch (giftType)
		{
		case freeze:
			m_gifts.push_back(std::make_unique<FreezeGift>(location,
				textures->getTexture(freezeGiftTexture)));
			
			break;
		case addTime:
			m_gifts.push_back(std::make_unique<TimeGift>(location,
				textures->getTexture(timeGiftTexture)));
			break;
		case addLife:
			m_gifts.push_back(std::make_unique<LifeGift>(location,
				textures->getTexture(lifeGiftTexture)));
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

void Board::removeGift(int index)
{
	m_gifts.erase(m_gifts.begin() + index);
}

void Board::removeDoor(int index)
{
	m_doors.erase(m_doors.begin() + index);
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

const std::vector<std::unique_ptr<Door>>& Board::getDoors() const
{
	return m_doors;
}


const std::vector<std::unique_ptr<Gift>>& Board::getGifts() const
{
	return m_gifts;
}

float Board::getWidth() const
{
	return m_width;
}

float Board::getHeight() const
{
	return m_length;
}
