#include "Level.h"

Level::Level( TextureManager* textures,
	SoundManager* sounds,
	Mouse* player)
	:  m_board() , m_level_time(DEFAULT_TIME), m_states(player, textures)
{
	m_player = player;
	m_textures = textures;
	m_sounds = sounds;
}

void Level::levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile ,
		bool &passed ,const int & levelNum)
{
	enum Gift_t giftStatus = noGift;
	int catMovement = 0;
	float deltaTime;
	m_board.readBoard(levelFile, m_player, m_cats , m_textures , m_level_time , m_levelMatrix);
	

	m_states.setLevelState(this->m_board.getHeight(), m_level_time , levelNum);

	window->create(sf::VideoMode(this->m_board.getWidth(),
		this->m_board.getHeight() + 100),
		"Mouse And Cat");
	
	while (window->isOpen() && Cheese::getCount() != 0 && this ->m_player ->getSouls() > 0)
	{
		deltaTime = m_clock.restart().asSeconds();
		window->clear();

		this->draw(window);
		
		window->display();

		if (this->m_states.getTimeAsSeconds() > m_level_time && m_level_time != NO_TIME)
		{
			this->m_player->suckSoul();
			break;
		}


		this->handleEvents(window);
		
		this->m_player->handleKeys(deltaTime, this->m_board.getHeight(),
									this->m_board.getWidth());

		if (catMovement < m_states.getTimeAsSeconds())
		{
			this->moveCats(deltaTime);
		}

		this->handleAllCollisions(giftStatus);

		this->giftsAffect(giftStatus , catMovement);
		
	}
	

	updateLevelUp(passed);


	
}

void Level::moveCats(float deltaTime)
{
	this->calcDistanceMat();

	
	for (int cat = 0; cat < this->m_cats.size(); cat++)
	{
		m_cats[cat]->move(deltaTime, m_levelMatrix);
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



void Level::handleAllCollisions(enum Gift_t & giftStatus)
{

	this->handleWallCollisions();
	this->handleGameObjectCollisions();
	this->handleDoorCollisions();
	this->handleGiftCollisions(giftStatus);
	this->handleCatColisions();


}


void Level::handleGiftCollisions(enum Gift_t& giftStatus)
{
	sf::FloatRect intersection;

	for (int gift = 0; gift < m_board.getGifts().size(); gift++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getGifts()[gift]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getGifts()[gift]->action(giftStatus);

			this->m_board.removeGift(gift);
		}
	}
}
void Level::handleCatColisions()
{
	for (int cat = 0; cat < m_cats.size(); cat++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(m_cats[cat] ->getSprite()
			->getGlobalBounds()))
		{
			// life -- , and reseting objects to the init pos
			m_sounds->playSound(gotHitSound);
			this->m_player->suckSoul();
			resetMovingObjects();
		}
	}
}
void Level::resetMovingObjects()
{
	this->m_player->resetPosition();

	for (int cat = 0; cat < m_cats.size(); cat++)
	{
		m_cats[cat]->resetPosition();
	}
}
void Level::updateLevelUp(bool& passed)
{
	if (Cheese::getCount() == 0)
	{
		passed = true;
	}
}
void Level::handleWallCollisions()
{
	sf::FloatRect intersection;

	for (int object = 0; object < m_board.getWalls().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getWalls()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getWalls()[object]->handleCollision(*m_player, intersection);
		}
	}
}

void Level::handleGameObjectCollisions()
{
	sf::FloatRect intersection;

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

void Level::handleDoorCollisions()
{
	sf::FloatRect intersection;

	for (int object = 0; object < m_board.getDoors().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getDoors()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			m_board.getDoors()[object]->handleCollision(*m_player, intersection);

			if (m_player->getKeys() > 0)
			{
				m_sounds->playSound(doorSound);
				m_player->removeKey();
				this->updateLevelMatrix(m_board.getDoors()[object]);
				this->m_board.removeDoor(object);

			}

		}
	}

}

void Level::updateLevelMatrix(const std::unique_ptr<Door> & door)
{ 
	sf::Vector2i doorMatPos = { static_cast<int>((door->getSprite()->getPosition().x) / TILE_WIDTH),
		static_cast<int>((door->getSprite()->getPosition().y) / TILE_LENGTH) };

	this->m_levelMatrix[doorMatPos.y][doorMatPos.x] = VALID;
}

void Level::removeCat()
{
	m_sounds->playSound(killCatGiftSound);
	int cat = (rand() % m_cats.size()) ;
	m_cats.erase(m_cats.begin() + cat);
}

void Level::addPlayerTime()
{
	int amount = rand() % AMOUNTS;

	m_sounds->playSound(timeGiftSound);
	switch (amount)
	{
	case lowAmount:
		m_level_time += LOW_TIME;
		break;
	case midAmount:
		m_level_time += MID_TIME;
		break;
	case largeAmount:
		m_level_time += LARGE_TIME;
		break;
	}

	m_states.setLevelTime(m_level_time);
}

void Level::handleFreeze(int &catMovement)
{
	m_sounds->playSound(freezeGiftSound);
	catMovement = m_states.getTimeAsSeconds() + FREEZE_TIME;
}

void Level::addPlayerLife()
{
	m_sounds->playSound(lifeGiftSound);
	if (this->m_player->getSouls() < SOULS_NUM)
	{
		m_player->addSouls(1);
	}
}

void Level::calcDistanceMat()
{
	sf::Vector2i mouseMatPos = { static_cast<int>((this->m_player->getSprite()->getPosition().x) / TILE_WIDTH),
							  static_cast<int>((this->m_player->getSprite()->getPosition().y) / TILE_LENGTH ) };
	this ->initMat();

	std::queue<sf::Vector2i> bfsQueue;

	const sf::Vector2i directions[] = { UP , DOWN , LEFT , RIGHT };

	m_levelMatrix[mouseMatPos.y][mouseMatPos.x] = 0;

	bfsQueue.push(mouseMatPos);

	while (!bfsQueue.empty())
	{
		sf::Vector2i currentPos = bfsQueue.front();
		bfsQueue.pop();

		for (const auto& direction : directions)
		{
			sf::Vector2i neighbor = currentPos + direction;

			// Check if the neighbor is within bounds and has not been visited yet
			if (neighbor.x >= 0 && neighbor.x < m_levelMatrix[0].size() &&
				neighbor.y >= 0 && neighbor.y < m_levelMatrix.size() &&
				m_levelMatrix[neighbor.y][neighbor.x] == VALID)
			{
				// Update the distance and enqueue the neighbor
				m_levelMatrix[neighbor.y][neighbor.x] = m_levelMatrix[currentPos.y][currentPos.x] + 1;
				bfsQueue.push(neighbor);
			}
		}	
	}
}

void Level::initMat()
{
	for (int row = 0; row < m_levelMatrix.size(); row++)
	{
		for (int col = 0; col < m_levelMatrix[row].size(); col++)
		{
			if (m_levelMatrix[row][col] != INFINIT)
			{
				m_levelMatrix[row][col] = VALID;
			}
		}
	}
}

void Level::giftsAffect(enum Gift_t& giftStatus , int & catMovement)
{
	switch (giftStatus)
	{
	case freeze:
		handleFreeze(catMovement);
		break;
	case killCat:
		removeCat(); 
		break;
	case addTime:
		addPlayerTime(); 
		break;
	case addLife:
		addPlayerLife();
		break;
	default:
		break;

	}

	giftStatus = noGift;
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