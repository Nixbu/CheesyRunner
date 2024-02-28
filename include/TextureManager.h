#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <Settings.h>

/*
	Class TextureManager :
		The class holds all the game textures.
*/

class TextureManager {
public:
	TextureManager();
	~TextureManager() = default;

	sf::Texture* getTexture(Texture_t wanted_texture) const;
private:
	std::vector<sf::Texture> m_textures;

	void load(sf::Texture& current, std::string texture_name);
};