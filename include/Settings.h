#pragma once
#include <SFML/Graphics.hpp>


//here we hold all the consts of the program.


enum Gift_t { freeze ,addLife , addTime, killCat , noGift
};


enum Texture_t {
	wallTexture = 0,
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
	backgroundTexture,
	mouseFrontTexture,
	mouseBackTexture,
	mouseLeftTexture,
	mouseRightTexture,
	catFrontTexture,
	catBackTexture,
	catLeftTexture,
	catRightTexture,
	instructionsTexture,
	clockTexture,
	youWonTexture,
	youLostTexture
};

enum Sound_t {
	keySound = 0,
	doorSound,
	gotHitSound,
	cheeseSound,
	lifeGiftSound,
	timeGiftSound,
	killCatGiftSound,
	freezeGiftSound,
	loseFromTimeSound,
	loseSound,
	winSound
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
SFX_VOLUME = 2;

const float TILE_WIDTH = 45,
TILE_LENGTH = 45,
CAT_VELOCITY = 60,
MOUSE_VELOCITY = 100,
DEFAULT_TIME = 100,
HEART_POS = 100,
HEART_OFFSET = 50,
STARTING_SOULS = 3,
SCORE_OFFSET = 300,
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

const int CHEESE_SCORE = 10,
GIFT_TYPES = 3,
KILL_CAT_GIFT = 3,
LOW_TIME = 15,
MID_TIME = 20,
LARGE_TIME = 30,
AMOUNTS = 3,
FREEZE_TIME = 5,
SOULS_NUM = 3,
INFINIT = 1000,
VALID = -1,
LEVEL_AND_TIME_OFFSET = 170,
TIMER_OFFSET = 55,
NO_TIME = -2,
GIFT_SCORE = 5,
DOOR_SCORE = 2,
LEVEL_UP_SCORE = 25 ,
CAT_SCORE = 5 ,
DISPLAY_TIME = 3;
			
enum AddTime{lowAmount  , midAmount , largeAmount};