#include "Cat.h"

Cat::Cat(sf::Vector2f position, sf::Texture* texture, float velocity, Mouse* mouse)
	: MovingObject(position, texture, velocity)
{
	m_player = mouse;
}

void Cat::move(float deltaTime,
	std::vector<std::vector<int>> boardMatrix)
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

sf::Vector2f Cat:: chooseMove(std::vector<std::vector<int>> boardMatrix) const
{
    // finding myself on the matrix
    sf::Vector2i myMatrixPosition = { (int)((this->getSprite()->getPosition().x+20) / TILE_WIDTH),
                        (int)((this->getSprite()->getPosition().y +20) / TILE_LENGTH) };


    int upDistance, downDistance, rightDistance, leftDistance;

    upDistance = downDistance = rightDistance = leftDistance = INFINIT;

    if (myMatrixPosition.x + 1 < boardMatrix[0].size())
    {
        // Right
        rightDistance = boardMatrix[myMatrixPosition.y][myMatrixPosition.x + 1];
    }
    

    if (myMatrixPosition.y + 1 < boardMatrix.size())
    {
        // Down
        downDistance = boardMatrix[myMatrixPosition.y+1][myMatrixPosition.x];
    }
    if (myMatrixPosition.x - 1 >= 0 )
    {
        // Left
        leftDistance = boardMatrix[myMatrixPosition.y][myMatrixPosition.x - 1];
    }

    if (myMatrixPosition.y - 1 >= 0 )
    {
        // UP
        upDistance = boardMatrix[myMatrixPosition.y -1][myMatrixPosition.x];
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
        min = INFINIT,
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
