#include "TextureManager.h"

//====================================================================
// Constructor
TextureManager::TextureManager()
{   
    sf::Texture currentTexture;

    load(currentTexture, "wall.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "cheese.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "key.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "door.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "bgTile1.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "bgTile2.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "bgTile3.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "bgTile4.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "bgTile5.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "playbutton.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "quitbutton.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "helpbutton.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "Heart.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "TimeGift.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "FreezeGift.png");
    m_textures.push_back(currentTexture);
    
    load(currentTexture, "LifeGift.png");
    m_textures.push_back(currentTexture);
    
    load(currentTexture, "DeadCatGift.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "Background.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "mouseFront.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "mouseBack.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "mouseLeft.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "mouseRight.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "catFront.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "catBack.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "catLeft.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "catRight.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "instructions.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "clocktexTure.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "youWon.png");
    m_textures.push_back(currentTexture);

    load(currentTexture, "youLost.png");
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

    current.setSmooth(true);
}

