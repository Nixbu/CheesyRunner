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
	exitBtnTexture,
	playBtnTexture,
	helpBtnTexture
};

const sf::Vector2f BUTTON_SCALE = { 1 ,1 } ;

const float TILE_WIDTH = 40,
		  TILE_LENGTH = 40;