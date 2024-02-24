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

void Level::levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile)
{
	enum Gift_t giftStatus = noGift;
	int catMovement = 0;
	float deltaTime;
	m_board.readBoard(levelFile, m_player, m_cats , m_textures,
		m_sounds, m_level_time);
	

	m_states.setLevelState(this->m_board.getHeight(), m_level_time);

	window->create(sf::VideoMode(this->m_board.getWidth(),
		this->m_board.getHeight() + 100),
		"Mouse And Cat");
	
	while (window->isOpen() && Cheese::getCount() != 0)
	{
		deltaTime = m_clock.restart().asSeconds();
		window->clear();

		this->draw(window);
		
		window->display();

		this->handleEvents(window);

		this->m_player->handleKeys(deltaTime);

		this->moveCats(deltaTime, this->m_board.getBoardMatrix());

		this->handleAllCollisions(giftStatus);

		this->giftsAffect(giftStatus , catMovement);
		
	}
}

void Level::moveCats(float deltaTime, std::vector<std::vector<bool>> boardMatrix)
{
	for (int cat = 0; cat < this->m_cats.size(); cat++)
	{
		m_cats[cat]->move(deltaTime, boardMatrix);
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
				m_player->removeKey();
				this->m_board.removeDoor(object);

			}

		}
	}

}

void Level::removeCat()
{
	int cat = (rand() % m_cats.size()) ;
	m_cats.erase(m_cats.begin() + cat);
}

void Level::addPlayerTime()
{
	int amount = rand() % AMOUNTS;

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
	catMovement = m_states.getTimeAsSeconds() + FREEZE_TIME;
}

void Level::addPlayerLife()
{
	if (this->m_player->getSouls() < SOULS_NUM)
	{
		m_player->addSouls(1);
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