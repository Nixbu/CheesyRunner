#include "Gift.h"

Gift::Gift(sf::Vector2f position, sf::Texture* texture, Gift_t giftType) :
	StaticObject(position , texture) , m_type(giftType)
{
}
