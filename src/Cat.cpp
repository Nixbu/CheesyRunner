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

#include <stack>

bool Cat::dfsChasingAlgorithm(std::vector<std::vector<bool>>& boardMatrix, sf::Vector2i startPos, sf::Vector2i mouseMatrixPosition) const
{
    std::stack<sf::Vector2i> stack;
    stack.push(startPos);

    while (!stack.empty()) {
        sf::Vector2i currentPos = stack.top();
        stack.pop();

        if (!boardMatrix[currentPos.y][currentPos.x]) {
            continue;  // Skip if already visited
        }

        if (currentPos == mouseMatrixPosition) {
            return true;  // Found the target
        }

        

        // Explore the right direction
        if (currentPos.x + 1 < boardMatrix[0].size()) {
            stack.push({ currentPos.x + 1, currentPos.y });
        }

        // Explore the down direction
        if (currentPos.y + 1 < boardMatrix.size()) {
            stack.push({ currentPos.x, currentPos.y + 1 });
        }

        // Explore the left direction
        if (currentPos.x - 1 >= 0) {
            stack.push({ currentPos.x - 1, currentPos.y });
        }

        // Explore the up direction
        if (currentPos.y - 1 >= 0) {
            stack.push({ currentPos.x, currentPos.y - 1 });
        }

        // Mark the current position as visited
        boardMatrix[currentPos.y][currentPos.x] = false;
    }

    return false;  // Target not found
}

sf::Vector2f Cat::chooseMove(std::vector<std::vector<bool>> boardMatrix) const
{
    sf::Vector2i myMatrixPosition = { (int)(this->getSprite()->getPosition().x / TILE_WIDTH),
                        (int)(this->getSprite()->getPosition().y / TILE_LENGTH) },
        mouseMatrixPosition = { (int)(this->m_player->getSprite()->getPosition().x / TILE_WIDTH),
                        (int)(this->m_player->getSprite()->getPosition().y / TILE_LENGTH) };

    if (myMatrixPosition.x + 1 < boardMatrix[0].size() && boardMatrix[myMatrixPosition.y][myMatrixPosition.x + 1])
    {
        if (dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x + 1, myMatrixPosition.y),
            mouseMatrixPosition))
        {
            return RIGHT;
        }
    }

    if (myMatrixPosition.y + 1 < boardMatrix.size() && boardMatrix[myMatrixPosition.y + 1][myMatrixPosition.x])
    {
        if (dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x, myMatrixPosition.y + 1),
            mouseMatrixPosition))
        {
            return DOWN;
        }
    }

    if (myMatrixPosition.x - 1 >= 0 && boardMatrix[myMatrixPosition.y][myMatrixPosition.x - 1])
    {
        if (dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x - 1, myMatrixPosition.y),
            mouseMatrixPosition))
        {
            return LEFT;
        }
    }


    if (myMatrixPosition.y - 1 >= 0 && boardMatrix[myMatrixPosition.y - 1][myMatrixPosition.x])
    {
        if (dfsChasingAlgorithm(boardMatrix,
            sf::Vector2i(myMatrixPosition.x, myMatrixPosition.y - 1),
            mouseMatrixPosition))
        {
            return UP;
        }
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
