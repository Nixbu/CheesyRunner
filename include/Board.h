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


class Board {
public:
	Board(std::ifstream levelFile, Mouse* mouse,
		std::vector<std::unique_ptr<Cat>>& cats,
		const TextureManager& textures);

	~Board() = default;

	void removeObject(int index);
private:
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	std::vector<std::unique_ptr<BackgroundTile>> m_bgTiles;
	float m_width,
		m_length;
};