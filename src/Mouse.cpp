#include "Mouse.h"

// ctor
Mouse::Mouse(sf::Vector2f position, sf::Texture* texture,
	float velocity,
	SoundManager * sounds,
	TextureManager* textures)
	: MovingObject(position, texture, MOUSE_VELOCITY),
	m_keys(0), m_life(SOULS_NUM), m_score(0),
	m_numOfCheese(0)
{
	m_sounds = sounds;
	m_textures = textures;
}
//======================================================
void Mouse::setKeys(int keys)
{
	this->m_keys = keys;
}
//======================================================
void Mouse::addKey()
{
	m_keys++;
}
//======================================================
void Mouse::removeKey()
{
	m_keys--;
}
//======================================================
void Mouse::setCheese(int cheese)
{
	this->m_numOfCheese = cheese;
}
//======================================================
int Mouse::getCheese() const
{
	return this->m_numOfCheese;
}
//======================================================
int Mouse::getKeys() const
{
	return this->m_keys;
}
//======================================================
int Mouse::getSouls() const
{
	return m_life;
}
//======================================================
int Mouse::getScore() const
{
	return m_score;
}
//======================================================
void Mouse::suckSoul()
{
	this->m_life--;
}
//======================================================
void Mouse::addSouls(int soulNum)
{
	m_life += soulNum;
}
//======================================================
// 
void Mouse::move(sf::Vector2i direction, float deltaTime,
	float boardHeight, float boardWidth)
{
	this->setDirection(direction);

	this->setSpriteDirection(direction);


	if (checkValidPos(boardHeight, boardWidth, deltaTime, direction))
	{
		this->getSprite()->move(this->getDirection().x * deltaTime * this->getVelocity(),
			this->getDirection().y * deltaTime * this->getVelocity());
	}
	
}

//=============================================================================
// The function sets the updated sprite direction
void Mouse::setSpriteDirection(sf::Vector2i direction)
{
	Texture_t wantedTexture;

	if (direction == UP)
	{
		wantedTexture = mouseBackTexture;
	}
	else if(direction == DOWN)
	{
		wantedTexture = mouseFrontTexture;
	}
	else if (direction == LEFT)
	{
		wantedTexture = mouseLeftTexture;
	}
	else
	{
		wantedTexture = mouseRightTexture;
	}


	this->getSprite()->setTexture(*m_textures->getTexture(wantedTexture));
}

//=============================================================================
// The function checkes if the new mouse position is within the board
bool Mouse::checkValidPos(float boardHeight, float boardWidth, 
	float deltaTime, sf::Vector2i direction)
{
	sf::FloatRect myRec = this->getSprite()->getGlobalBounds();

	sf::Vector2f addedMovement;

	addedMovement.x += (direction == DOWN || direction == RIGHT) ?
		myRec.left + myRec.width + deltaTime * this->getVelocity() * direction.x :
		myRec.left + deltaTime * this->getVelocity() * direction.x;
	addedMovement.y += (direction == DOWN || direction == RIGHT) ?
		myRec.top + myRec.height + deltaTime * this->getVelocity() * direction.y :
		myRec.top + deltaTime * this->getVelocity() * direction.y;
	
	if (addedMovement.x >=0 && addedMovement.x < boardWidth
		&& addedMovement.y >= 0 && addedMovement.y < boardHeight)
	{
		return true;
	}

	return false;
}

//=============================================================================
void Mouse::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
	// double dispatch
	gameObject.handleCollision(*this, intersection);
}

//=============================================================================
void Mouse::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
	this->m_sounds->playSound(cheeseSound);
	m_score += CHEESE_SCORE;
}

//=============================================================================
void Mouse::handleCollision(Door& gameObject, sf::FloatRect intersection)
{

	this->getSprite()->move((-1) * intersection.width * this->getDirection().x,
		(-1) * intersection.height * this->getDirection().y);
}
//======================================================
void Mouse::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Mouse::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
	this->m_sounds->playSound(keySound);
	this->addKey();
}
//======================================================
void Mouse::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
	this->getSprite()->move((-1) * intersection.width * this->getDirection().x,
		(-1) * intersection.height * this->getDirection().y);
}
//======================================================
void Mouse::handleCollision(Gift& gift)
{
	m_score += GIFT_SCORE;
}
//======================================================
void Mouse::addScore(const int& score)
{
	m_score += score;
}
//======================================================
// handling the player movement
void Mouse::handleKeys(float deltaTime,
	float boardHeight, float boardWidth)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->move(LEFT, deltaTime,
			boardHeight, boardWidth);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->move(RIGHT, deltaTime,
			boardHeight, boardWidth);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->move(UP, deltaTime,
			boardHeight, boardWidth);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->move(DOWN, deltaTime,
			boardHeight, boardWidth);
	}
}



