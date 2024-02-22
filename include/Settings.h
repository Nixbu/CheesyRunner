#pragma once
#include <SFML/Graphics.hpp>

enum Gift_t { freeze , addTime , killCat , noGift
};


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
	heartTexture
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
MOUSE_VELOCITY = 300,
DEFAULT_TIME = 100,
HEART_POS = 100,
HEART_OFFSET = 50,
STARTING_SOULS = 3,
SCORE_OFFSET = 250,
TIME_OFFSET = 300;

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

const int CHEESE_SCORE = 10 ,
		   GIFT_TYPES = 2 ,
	NUM_OF_GIFTS_FOR_EZ_LEVEL = 3 ,
	LOW_TIME =15 ,
	MID_TIME = 20,
	LARGE_TIME = 30 ,
	AMOUNTS = 3 ,
	FREEZE_TIME = 5;
			
enum AddTime{lowAmount  , midAmount , largeAmount};