#include "TextureManager.h"

//====================================================================
// Constructor
TextureManager::TextureManager()
{   
    sf::Texture currentTexture;

    load(currentTexture, "mouse.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "cat.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "wall.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "cheese.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "gift.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "key.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "door.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "space.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "playbutton.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "quitbutton.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "helpbutton.png");
    m_textures.push_back(currentTexture);

}

//===================================================
// Get pointer to wanted texture
sf::Texture* TextureManager::getTexture(Texture_t wanted_texture) const
{
    return (sf::Texture*)&m_textures[wanted_texture];
}


//===================================================
// Load texture from file
void TextureManager::load(sf::Texture& current, 
    std::string texture_name)
{
    if (!current.loadFromFile(texture_name))
    {
        std::cout << "faild to load texture " << std::endl;
        exit(EXIT_FAILURE);
    }
}

