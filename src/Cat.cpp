#include "Cat.h"

Cat::Cat(sf::Vector2f position, sf::Texture* texture, float velocity, Mouse* mouse)
	: MovingObject(position, texture, velocity)
{
	m_player = mouse;
}

void Cat::move(float deltaTime,
	std::vector<std::vector<bool>> boardMatrix)
{
	sf::Vector2f wantedDirection = chooseMove(boardMatrix);

	this->setDirection(wantedDirection);

	this->getSprite()->move(this->getDirection().x * deltaTime * this->getVelocity(),
		this->getDirection().y * deltaTime * this->getVelocity());


}

void Cat::draw(sf::RenderWindow* window) const
{
	window->draw(*(this->getSprite()));
}

int Cat::dfsChasingAlgorithm(std::vector<std::vector<bool>> & boardMatrix, 
    sf::Vector2i newPos, 
    sf::Vector2i mouseMatrixPosition) const
{
    if (!boardMatrix[newPos.y][newPos.x])
    {
        return (int)INFINITY;
    }

    if (newPos == mouseMatrixPosition)
    {
        return 0;
    }

    int upDistance,
        downDistance,
        rightDistance,
        leftDistance;

    // Update visited tile
    boardMatrix[newPos.y][newPos.x] = false;


    if (newPos.x + 1 < boardMatrix[0].size())
    {
        // Right
        rightDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(newPos.x + 1, newPos.y),
            mouseMatrixPosition);
    }

    if (newPos.y + 1 < boardMatrix.size())
    {
        // Down
        downDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(newPos.x, newPos.y + 1),
            mouseMatrixPosition);
    }
    if (newPos.x - 1 >= 0)
    {
        // Left
        leftDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(newPos.x - 1, newPos.y),
            mouseMatrixPosition);
    }

    if (newPos.y - 1 >= 0)
    {
        // UP
        upDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(newPos.x, newPos.y - 1),
            mouseMatrixPosition);
    }



    auto min1 = std::min(rightDistance, upDistance),
        min2 = std::min(downDistance, leftDistance);

    return std::min(min1, min2);

    
}

sf::Vector2f Cat::chooseMove(std::vector<std::vector<bool>> boardMatrix) const
{
    sf::Vector2i myMatrixPosition = { (int)(this->getSprite()->getPosition().x / TILE_WIDTH),
                        (int)(this->getSprite()->getPosition().y / TILE_LENGTH) },
        mouseMatrixPosition = { (int)(this->m_player->getSprite()->getPosition().x / TILE_WIDTH),
                        (int)(this->m_player->getSprite()->getPosition().y / TILE_LENGTH) };
    int upDistance = 0,
        downDistance = 0,
        rightDistance = 0,
        leftDistance = 0;

    if (myMatrixPosition.x + 1 < boardMatrix[0].size())
    {
        // Right
        rightDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x + 1, myMatrixPosition.y),
            mouseMatrixPosition);
    }

    if (myMatrixPosition.y + 1 < boardMatrix.size())
    {
        // Down
        downDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x, myMatrixPosition.y + 1),
            mouseMatrixPosition);
    }

    if (myMatrixPosition.x - 1 >= 0)
    {
        // Left
        leftDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x - 1, myMatrixPosition.y),
            mouseMatrixPosition);
    }


    if (myMatrixPosition.y - 1 >= 0)
    {
        // Up
        upDistance = dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x, myMatrixPosition.y - 1),
            mouseMatrixPosition);
    }

    return findMinDirection(upDistance, downDistance, rightDistance, leftDistance);
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

sf::Vector2f Cat::findMinDirection(int upDistance, int downDistance,
    int rightDistance, int leftDistance) const
{
    int arr[4] = { upDistance, downDistance, rightDistance, leftDistance },
        min = (int)INFINITY,
        min_direction = 0;

    for (int direction = 0; direction < 4; direction++)
    {
        if (arr[direction] < min)
        {
            min = arr[direction];
            min_direction = direction;
        }
    }

    switch (min_direction)
    {
    case 0:
        return UP;
    case 1:
        return DOWN;
    case 2:
        return RIGHT;
    case 3:
        return LEFT;
    default:
        break;
    }
}
