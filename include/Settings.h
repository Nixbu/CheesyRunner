#pragma once
#include <SFML/Graphics.hpp>

enum Gift_t { freeze , addTime ,addLife , killCat , noGift
};


enum Texture_t {
	mouseTexture = 0,
	catTexture,
	wallTexture,
	cheeseTexture,
	keyTexture,
	doorTexture,
	bgTileTexture,
	bgTileTexture2,
	bgTileTexture3,
	bgTileTexture4,
	bgTileTexture5,
	playBtnTexture,
	exitBtnTexture,
	helpBtnTexture,
	heartTexture,
	timeGiftTexture,
	freezeGiftTexture,
	lifeGiftTexture,
	deadCatGiftTexture,
	backgroundTexture
};

enum Sound_t {
	keySound
};

enum Button_t {
	playBtn,
	helpBtn,
	exitBtn
};

const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867,
BG_TILES = 2,
BASE_TILE = bgTileTexture,
VOLUME = 1,
SFX_VOLUME = 50;

const float TILE_WIDTH = 40,
TILE_LENGTH = 40,
CAT_VELOCITY = 30,
MOUSE_VELOCITY = 170,
DEFAULT_TIME = 100,
HEART_POS = 100,
HEART_OFFSET = 50,
STARTING_SOULS = 3,
SCORE_OFFSET = 250,
TIME_OFFSET = 300;

const sf::Vector2f BUTTON_DEFA_SIZE = { 0.33f, 0.33f },
BUTTON_FLOATED_SIZE = { 0.4f, 0.4f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 - 200 },
HELP_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 },
EXIT_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
				WINDOW_MANAGER_HEIGHT / 2 + 200 } ,
	CAT_OFFSET = { 17 , 17 };

//Directions
const sf::Vector2i 
UP = { 0, -1 },
DOWN = { 0, 1 },
LEFT = { -1, 0 },
RIGHT = { 1, 0 },
STAND = { 0, 0 };

const int CHEESE_SCORE = 10 ,
		   GIFT_TYPES = 3 ,
	NUM_OF_GIFTS_FOR_EZ_LEVEL = 3 ,
	LOW_TIME =15 ,
	MID_TIME = 20,
	LARGE_TIME = 30 ,
	AMOUNTS = 3 ,
	FREEZE_TIME = 5 ,
	SOULS_NUM = 3,
	INFINIT = 1000 ,
	VALID = -1;
			
enum AddTime{lowAmount  , midAmount , largeAmount};