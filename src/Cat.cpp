#include "Cat.h"
//======================================================
// cat ctor
Cat::Cat(sf::Vector2f position, sf::Texture* texture, float velocity, Mouse* mouse,
    const TextureManager* textures)
	: MovingObject(position, texture, velocity)
{
	m_player = mouse;
    m_textures = textures;

}
//======================================================
// function moves the cat according to wanted direction

void Cat::move(float deltaTime,
    std::vector<std::vector<int>> boardMatrix)
{
    //picking best direction to get closer to the mouse 
    sf::Vector2i wantedDirection = chooseMove(boardMatrix);

    this->setDirection(wantedDirection);

    // using correct sprite 
    this->setSpriteDirection(wantedDirection);

    // moving the cat according to the direction
    this->getSprite()->move(this->getDirection().x * deltaTime * this->getVelocity(),
        this->getDirection().y * deltaTime * this->getVelocity());


}
//======================================================
// this function peaks the best direction to the cat according to the 
// distance matrix that we built using the bfs algorithm 
sf::Vector2i Cat:: chooseMove(std::vector<std::vector<int>> boardMatrix) const
{
    // finding myself on the matrix

    sf::Vector2f catPos = getSprite()->getPosition();

    sf::Vector2i dir = this->getDirection();

    // needed offsts
    if (dir == RIGHT || dir == DOWN)
    {
        catPos -= CAT_OFFSET;
       
    }
    if(dir == LEFT || dir == UP)
    {
        catPos += CAT_OFFSET;       
    }
    // finding cats position on the matrix
    sf::Vector2i myMatrixPosition = { (int)(catPos.x / TILE_WIDTH),
                        (int)(catPos.y / TILE_LENGTH ) };


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
    // returnning the direction that will be the best to catch the mouse
    // ( minimum steps on the matrix )
    return findMinDirection(upDistance, downDistance, rightDistance, leftDistance);

    
}
//======================================================
void Cat::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}
//======================================================
void Cat::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
//======================================================
// function returns the minimal direction vector - 
// the minimal side will be the best move for the cat to catch the mouse.
// according to this direction the cat moves
sf::Vector2i Cat::findMinDirection(int upDistance, int downDistance,
    int rightDistance, int leftDistance) const
{
    int arr[4] = { upDistance, downDistance, rightDistance, leftDistance },
        min = INFINIT,
        min_direction = 0;
    // finding min
    for (int direction = 0; direction < 4; direction++)
    {
        if (arr[direction] < min)
        {
            min = arr[direction];
            min_direction = direction;
        }
    }
    // return the direction
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
//======================================================
// function sets the correct sprite according to the cats moving 
//direction
void Cat::setSpriteDirection(sf::Vector2i direction)
{
    Texture_t wantedTexture;

    if (direction == UP)
    {
        wantedTexture = catBackTexture;
    }
    else if (direction == DOWN)
    {
        wantedTexture = catFrontTexture;
    }
    else if (direction == LEFT)
    {
        wantedTexture = catLeftTexture;
    }
    else
    {
        wantedTexture = catRightTexture;
    }


    this->getSprite()->setTexture(*m_textures->getTexture(wantedTexture));
}
