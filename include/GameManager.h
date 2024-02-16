#pragma once

#include "TextureManager.h"
#include <vector>
#include "Button.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager() = default;

private:
	TextureMangager m_texturs;
	Menu m_menu(const TextureManager & textures)
};
