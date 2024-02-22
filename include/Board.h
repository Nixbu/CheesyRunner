#pragma once

#include <vector>
#include "GameObject.h"
#include <fstream>
#include <string>
#include "Settings.h"
#include "BackgroundTile.h"
#include "Mouse.h"
#include "Cat.h"
#include "TextureManager.h"
#include <memory>
#include "Cheese.h"
#include "Key.h"
#include "Door.h"
#include "Wall.h"
#include "Gift.h"
#include "FreezeGift.h"
#include "TimeGift.h"
#include "KillCatGift.h"


class Board {
public:
	Board();
	void readBoard(std::ifstream * levelFile, Mouse* mouse,
		std::vector<std::unique_ptr<Cat>>& cats ,
		const TextureManager * textures ,
		int &leveltime);
	//Board(const Board& other);

	~Board() = default;
	void genarateGift(int numOfGifts, sf::Vector2f location, const TextureManager* textures);
	void removeObject(int index);
	void draw(sf::RenderWindow * window );

	const std::vector<std::unique_ptr<Wall>>& getWalls() const;
	const std::vector<std::unique_ptr<GameObject>>& getGameObjects() const;

	float getWidth() const;
	float getHeight() const;

private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	std::vector<std::unique_ptr<Wall>> m_walls;
	std::vector<std::unique_ptr<BackgroundTile>> m_bgTiles;
	std::vector<std::unique_ptr<Door>> m_doors;
	std::vector<std::unique_ptr<Gift>> m_gifts;
	float m_width,
		m_length;
};