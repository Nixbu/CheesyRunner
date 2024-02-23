#include "Cat.h"

Cat::Cat(sf::Vector2f position, sf::Texture* texture, float velocity, Mouse* mouse)
	: MovingObject(position, texture, velocity)
{
	m_player = mouse;
}

void Cat::move(float deltaTime,
	std::vector<std::vector<bool>> boardMatrix)
{
	sf::Vector2f wantedDirection = dfsChasingAlgorithm(boardMatrix);

	this->setDirection(wantedDirection);

	this->getSprite()->move(this->getDirection().x * deltaTime * this->getVelocity(),
		this->getDirection().y * deltaTime * this->getVelocity());


}

void Cat::draw(sf::RenderWindow* window) const
{
	window->draw(*(this->getSprite()));
}

sf::Vector2f Cat::dfsChasingAlgorithm(std::vector<std::vector<bool>> boardMatrix) const
{
	sf::Vector2i myMatrixPosition = { (int)(this->getSprite()->getPosition().x / TILE_WIDTH),
						(int)(this->getSprite()->getPosition().y / TILE_LENGTH) },
		mouseMatrixPosition = { (int)(this->m_player->getSprite()->getPosition().x / TILE_WIDTH),
						(int)(this->m_player->getSprite()->getPosition().y / TILE_LENGTH) };

    if (myMatrixPosition.x + 1 < boardMatrix[0].size() && boardMatrix[myMatrixPosition.y][myMatrixPosition.x + 1])
    {
        std::cout << boardMatrix[0].size();
        return RIGHT;
    }

    if (myMatrixPosition.y + 1 < boardMatrix.size() && boardMatrix[myMatrixPosition.y + 1][myMatrixPosition.x])
    {
        return DOWN;
    }

    if (myMatrixPosition.x - 1 >= 0 && boardMatrix[myMatrixPosition.y][myMatrixPosition.x - 1])
    {
        return LEFT; 
    }


    if (myMatrixPosition.y - 1 >= 0 && boardMatrix[myMatrixPosition.y - 1][myMatrixPosition.x])
    {
        return UP;
    }

    return STAND;
}

void Cat::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}

void Cat::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
