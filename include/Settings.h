#pragma once
#include <SFML/Graphics.hpp>

enum Gift_t { freeze , killCat , addTime  };

enum Texture_t {
	mouseTexture,
	catTexture,
	wallTexture,
	cheeseTexture,
	giftTexture,
	keyTexture,
	doorTexture,
	bgTileTexture,
	playBtnTexture,
	exitBtnTexture,
	helpBtnTexture
};

enum Button_t {
	playBtn,
	helpBtn,
	exitBtn
};

const float TILE_WIDTH = 40,
TILE_LENGTH = 40,
WINDOW_MANAGER_WIDTH = 1200,
WINDOW_MANAGER_HEIGHT = 800;

const sf::Vector2f BUTTON_DEFA_SIZE = { 180, 105 },
BUTTON_FLOATED_SIZE = { 210, 125 },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 - 200 },
HELP_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 },
EXIT_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 + 200 };