#pragma once

#include "MovingObject.h"
#include "Settings.h"
#include "SoundManager.h"
#include "TextureManager.h"

/*
	Class Mouse:
		The class represents the player in the game.
*/

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

	void suckSoul();
	void addSouls(int soulNum);
	void move(sf::Vector2i direction, float deltaTime,
		float boardHeight, float boardWidth);
	void handleKeys(float deltaTime,
		float boardHeight, float boardWidth);

	virtual void handleCollision(GameObject& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Mouse& gameobject, sf::FloatRect intersection) {};
	virtual void handleCollision(Cheese& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Door& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Cat& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Key& gameObject, sf::FloatRect intersection);
	virtual void handleCollision(Wall& gameObject, sf::FloatRect intersection);
	void handleCollision(Gift& gift);
	void addScore(const int& score);


private:
	int m_life,
		m_keys,
		m_score,
		m_numOfCheese;
	SoundManager* m_sounds;
	TextureManager* m_textures;

	void setSpriteDirection(sf::Vector2i direction);
	bool checkValidPos(float boardHeight, float boardWidth,
		float deltaTime, sf::Vector2i direction);

};