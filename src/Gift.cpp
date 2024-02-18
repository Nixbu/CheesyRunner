#include "Gift.h"

Gift::Gift(sf::Vector2f position, sf::Texture* texture, Gift_t giftType) :
	StaticObject(position , texture) , m_type(giftType)
{
}

void Gift::action()
{
}

void Gift::handleCollision(GameObject& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Mouse& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Cheese& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Door& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Cat& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Key& gameObject, sf::FloatRect intersection)
{
}

void Gift::handleCollision(Wall& gameObject, sf::FloatRect intersection)
{
}
