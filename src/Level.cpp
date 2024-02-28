#include "Level.h"
//======================================================
// ctor
Level::Level( TextureManager* textures,
	SoundManager* sounds,
	Mouse* player)
	:  m_board() , m_level_time(DEFAULT_TIME), m_states(player, textures)
{
	m_player = player;
	m_textures = textures;
	m_sounds = sounds;
}
//======================================================
// function handles the main level loop 
void Level::levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile ,
		bool &passed ,const int & levelNum , bool & exit)
{
	enum Gift_t giftStatus = noGift;
	int catMovement = 0 , catNum;
	float deltaTime;

	// reading the level from the file
	m_board.readBoard(levelFile, m_player, m_cats , m_textures , m_level_time , m_levelMatrix);
	catNum = this->m_cats.size();

	// updating the states of the player according to the level read
	m_states.setLevelState(this->m_board.getHeight(), m_level_time , levelNum);


	window->create(sf::VideoMode(this->m_board.getWidth(),
		this->m_board.getHeight() + 100),
		"Mouse And Cat");
	// play loop
	while (window->isOpen() &&
		Cheese::getCount() != 0 && 
		this ->m_player ->getSouls() > 0)
	{
		deltaTime = m_clock.restart().asSeconds();
		window->clear();

		this->draw(window);
		
		window->display();


		// eliminate the player if run out of time (happens only in leveles with time)
		if (this->m_states.getTimeAsSeconds() > m_level_time && m_level_time != NO_TIME)
		{
			this->m_sounds->playSound(loseFromTimeSound);
			this->m_player->suckSoul();
			break;
		}


		this->handleEvents(window, exit);
		
		this->m_player->handleKeys(deltaTime, this->m_board.getHeight(),
									this->m_board.getWidth());
		this->handleEvents(window , exit);

		this->m_player->handleKeys(deltaTime, this->m_board.getHeight(),
									this->m_board.getWidth());

		// move the cat if not freezed
		if (catMovement < m_states.getTimeAsSeconds())
		{
			this->moveCats(deltaTime);
		}

		// handle colisions with the player
		this->handleAllCollisions(giftStatus);

		// taking care of gift affects( adding time , freezing the cats ...)
		this->giftsAffect(giftStatus , catMovement);
		
	}
	
	// if the level is completed adding the needed score
	this->updateLevelUpAndScore(passed , catNum);


	
}
//======================================================
// functions move the cats 
void Level::moveCats(float deltaTime)
{
	this->calcDistanceMat();

	
	for (int cat = 0; cat < this->m_cats.size(); cat++)
	{
		m_cats[cat]->move(deltaTime, m_levelMatrix);
	}
}
//======================================================
void Level::handleEvents(sf::RenderWindow * window , bool &exit)
{
	for (auto event = sf::Event{}; window->pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			exit = true;
			window->close();
			break;
		}
	}
}
//======================================================
// functions handle the collisions with the player
void Level::handleAllCollisions(enum Gift_t & giftStatus)
{

	this->handleWallCollisions();
	this->handleGameObjectCollisions();
	this->handleDoorCollisions();
	this->handleGiftCollisions(giftStatus);
	this->handleCatColisions();


}
//======================================================
// function handles colisions with gifts
void Level::handleGiftCollisions(enum Gift_t& giftStatus)
{
	sf::FloatRect intersection;

	for (int gift = 0; gift < m_board.getGifts().size(); gift++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getGifts()[gift]->getSprite()->getGlobalBounds(), intersection))
		{
			this->m_player->handleCollision(*(m_board.getGifts()[gift]));

			m_board.getGifts()[gift]->action(giftStatus);

			this->m_board.removeGift(gift);
		}
	}
}
//======================================================
// function handles colisions with cats
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
//======================================================
// if needed function resetting the moving objects to the initial position 
// in the level
void Level::resetMovingObjects()
{
	this->m_player->resetPosition();

	for (int cat = 0; cat < m_cats.size(); cat++)
	{
		m_cats[cat]->resetPosition();
	}
}
//======================================================
// if the level is completed function sets a flag and update 
// the players score accordingly
void Level::updateLevelUpAndScore(bool& passed , const int & catNum)
{
	if (Cheese::getCount() == 0)
	{
		passed = true;
	}
	if (passed)
	{
		this->m_player->addScore(LEVEL_UP_SCORE + catNum * CAT_SCORE);
	}

}
//======================================================
// function handles walls coilision
void Level::handleWallCollisions()
{
	sf::FloatRect intersection;

	for (int object = 0; object < m_board.getWalls().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getWalls()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			// double dispatch
			m_board.getWalls()[object]->handleCollision(*m_player, intersection);
		}
	}
}
//======================================================
// function handles game object colisions  using polymorphizm
void Level::handleGameObjectCollisions()
{
	sf::FloatRect intersection;

	for (int object = 0; object < m_board.getGameObjects().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getGameObjects()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			// double dispatch
			m_board.getGameObjects()[object]->handleCollision(*m_player, intersection);

			this->m_board.removeObject(object);
		}
	}
}
//======================================================
// function handles ddoors colisions 
void Level::handleDoorCollisions()
{
	sf::FloatRect intersection;

	for (int object = 0; object < m_board.getDoors().size(); object++)
	{
		if (m_player->getSprite()->getGlobalBounds().intersects(
			m_board.getDoors()[object]->getSprite()->getGlobalBounds(), intersection))
		{
			// double dispatch
			m_board.getDoors()[object]->handleCollision(*m_player, intersection);

			// has key
			if (m_player->getKeys() > 0)
			{
				m_sounds->playSound(doorSound);
				m_player->removeKey();
				this->updateLevelMatrix(m_board.getDoors()[object]);
				this->m_board.removeDoor(object);
				this->m_player->addScore(DOOR_SCORE);

			}

		}
	}

}

//====================================================== 
// Update the level matrix that a door has been removed,
// for correct bfs
void Level::updateLevelMatrix(const std::unique_ptr<Door> & door)
{ 
	sf::Vector2i doorMatPos = { static_cast<int>((door->getSprite()->getPosition().x) / TILE_WIDTH),
		static_cast<int>((door->getSprite()->getPosition().y) / TILE_LENGTH) };

	this->m_levelMatrix[doorMatPos.y][doorMatPos.x] = VALID;
}
//====================================================== 
void Level::removeCat()
{
	m_sounds->playSound(killCatGiftSound);
	int cat = (rand() % m_cats.size()) ;
	m_cats.erase(m_cats.begin() + cat);
}
//====================================================== 
// function adds time to the player if he ate the time gift
// the time added is randomly chosen ( 15 , 20 , 30)
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
//====================================================== 
// function handles the freeze gift affect
void Level::handleFreeze(int &catMovement)
{
	m_sounds->playSound(freezeGiftSound);
	catMovement = m_states.getTimeAsSeconds() + FREEZE_TIME;
}
//====================================================== 
// function handles the life gift affect
void Level::addPlayerLife()
{
	m_sounds->playSound(lifeGiftSound);
	if (this->m_player->getSouls() < SOULS_NUM)
	{
		m_player->addSouls(1);
	}
}
//======================================================
// This function is calculating the distance matrix from the player's position
// using BFS on a grid-based map. The distance matrix represents the minimum distance from 
// each valid tile on the map to the player's current position.
// the cats use it to choose the best move towards the player.
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
//======================================================
// function initializes the distance
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
//======================================================
// function implements the gift affects, it gets the gifts flag
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
//======================================================
// function draws all the level objects
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