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
	helpBtnTexture,
};

enum Button_t {
	playBtn,
	helpBtn,
	exitBtn
};

const float TILE_WIDTH = 40,
TILE_LENGTH = 40,
WINDOW_MANAGER_WIDTH = 1200,
WINDOW_MANAGER_HEIGHT = 800,
CAT_VELOCITY = 30,
MOUSE_VELOCITY = 100;

const sf::Vector2f BUTTON_DEFA_SIZE = { 180.0f, 105.0f },
BUTTON_FLOATED_SIZE = { 210.0f, 125.0f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 - 200 },
HELP_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 },
EXIT_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 + 200 };

//Directions
const sf::Vector2f 
UP = { 0, -1 },
DOWN = { 0, 1 },
LEFT = { -1, 0 },
RIGHT = { 1, 0 },
STAND = { 0, 0 };

const int CHEESE_SCORE = 10; 