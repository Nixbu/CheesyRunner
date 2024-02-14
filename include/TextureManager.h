#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager {
public:
	TextureManager();
	~TextureManager() = default;
private:
	std::vector<sf::Texture> m_textures;
};