#pragma once

#include "Board.h"
#include <vector>
#include "Cat.h"
#include "Mouse.h"
#include <fstream>
#include "TextureManager.h"
#include "SoundManager.h"
#include <SFML/Graphics.hpp>
#include "States.h"
#include <queue>

/*
	Class Level:
		The class represents a level of the game .
*/

class Level {
public:
	Level(TextureManager* textures,
		SoundManager* sounds,
		Mouse* player);
		
	virtual ~Level() = default;

	void levelLoop(sf::RenderWindow * window , std::ifstream  *levelFile 
		, bool &passed , const int& levelnum , bool &exit);
	void draw(sf::RenderWindow* window);
	void handleEvents(sf::RenderWindow* window , bool &exit);
	void handleAllCollisions(enum Gift_t& giftStatus);
	void giftsAffect(enum Gift_t& giftStatus , int& catMovement);
	void moveCats(float deltaTime);
	
	
	


private:
	Board m_board;
	sf::Clock m_clock;

	int m_level_time;
	std::vector<std::unique_ptr<Cat>> m_cats;
	TextureManager* m_textures;
	SoundManager* m_sounds;
	Mouse* m_player;
	States m_states;
	std::vector<std::vector <int>> m_levelMatrix;

	void removeCat();
	void addPlayerTime();
	void handleFreeze(int& catMovement);
	void addPlayerLife();
	void calcDistanceMat();
	void initMat();
	void handleWallCollisions();
	void handleGameObjectCollisions();
	void handleDoorCollisions();
	void handleGiftCollisions(enum Gift_t& giftStatus);
	void handleCatColisions();
	void resetMovingObjects();
	void updateLevelUp(bool& passed);
	void updateLevelMatrix(const std::unique_ptr<Door> & door);
	void updateLevelUpAndScore(bool& passed , const int& catNum);
};
