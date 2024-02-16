#pragma once

#include "TextureManager.h"
#include <vector>
#include "Button.h"
#include "Menu.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager() = default;
	void run();

private:
	TextureManager m_textures;
	Menu m_menu;
};
