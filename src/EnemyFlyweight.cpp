#include "../include/EnemyFlyweight.h"

#include <sstream>
#include <string>
#include <iomanip>

EnemyFlyweight::EnemyFlyweight(  const std::string &path, float scale )
{
    // Reserve memory for textures and sprites vector
    textures.resize(TextureType::N_TEXTURE_TYPE);
    for (int i = 0; i < N_TEXTURE_TYPE; ++i)
        textures[i].resize(EnemyFlyweight::N_TEXTURES_PER_TYPE);

    sprites.resize(TextureType::N_TEXTURE_TYPE);
    for (int i = 0; i < N_TEXTURE_TYPE; ++i)
        sprites[i].resize(EnemyFlyweight::N_TEXTURES_PER_TYPE);

    // Load textures
    loadTextures( path );

    // Load textures to sprites
    loadSprites( scale );
}

EnemyFlyweight::~EnemyFlyweight() = default;

void EnemyFlyweight::loadTextures( const std::string &path ) {
    std::string type_name[] = {"attack", "die", "hurt", "idle", "jump", "run", "walk"};

    for (int i = 0; i < EnemyFlyweight::TextureType::N_TEXTURE_TYPE; ++i)
    {
        for(int j = 0; j < EnemyFlyweight::N_TEXTURES_PER_TYPE; ++j)
        {
            std::ostringstream oss;
            oss << path << "/" << type_name[i] << "_" << std::setfill('0') << std::setw(2) << j << ".png";
            if(!textures[i][j].loadFromFile(oss.str()))
            {
                // If texture load error
                throw std::invalid_argument("Can not load textures from: " + oss.str());
            }
            textures[i][j].setSmooth(true);
        }
    }
}

void EnemyFlyweight::loadSprites(float scale) {
    for (int i = 0; i < EnemyFlyweight::TextureType::N_TEXTURE_TYPE; ++i)
    {
        for(int j = 0; j < EnemyFlyweight::N_TEXTURES_PER_TYPE; ++j)
        {
            sprites[i][j].setTexture(textures[i][j]);
            if(scale != 1.0)
                sprites[i][j].setScale(scale, scale);
            sprites[i][j].setOrigin(sf::Vector2((scale*(float)textures[i][j].getSize().x) / 2.f,
                                                (scale*(float)textures[i][j].getSize().y)) );
        }
    }
}

sf::Sprite& EnemyFlyweight::getSprite(EnemyFlyweight::TextureType type, uint8_t n_th) {
    if(n_th >= EnemyFlyweight::N_TEXTURES_PER_TYPE)
        throw std::invalid_argument("Out of range 'n_th'");

    return sprites[type][n_th];
}



