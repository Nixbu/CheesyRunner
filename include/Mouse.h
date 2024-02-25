#pragma once

#include "MovingObject.h"
#include "Settings.h"
#include "SoundManager.h"
#include "TextureManager.h"

class Mouse :public MovingObject {
public:
	Mouse(sf::Vector2f position, sf::Texture* texture,
		float velocity,
		SoundManager* sounds,
		TextureManager* textures);
	~Mouse() = default;
	void setKeys(int keys);
	void addKey();
	void removeKey();
	void setCheese(int cheese);
	int getCheese() const;
	int getKeys() const;
	int getSouls() const;
	int getScore() const;

	void addSouls(int soulNum);
	void move(sf::Vector2i direction, float deltaTime);
	void draw(sf::RenderWindow * window) const override;
	void handleKeys(float deltaTime);

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameobject, sf::FloatRect intersection);
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);


private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;
	SoundManager* m_sounds;
	TextureManager* m_textures;

	void setSpriteDirection(sf::Vector2i direction);

};