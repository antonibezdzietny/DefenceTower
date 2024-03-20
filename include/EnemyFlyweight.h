#ifndef DEFENCETOWER_ENEMYFLYWEIGHT_H
#define DEFENCETOWER_ENEMYFLYWEIGHT_H

#include <SFML/Graphics.hpp>
#include <vector>

class EnemyFlyweight {
public:
    enum TextureType
    {
        ATTACK = 0,
        DIE,
        HURT,
        IDLE,
        JUMP,
        RUN,
        WALK,
        N_TEXTURE_TYPE,
    };

    static const int N_TEXTURES_PER_TYPE = 20;

public:
    explicit EnemyFlyweight(  const std::string &path, float scale );
    ~EnemyFlyweight();
    sf::Sprite& getSprite(TextureType type, uint8_t n_th);

private:
    std::vector<std::vector<sf::Texture>> textures;
    std::vector<std::vector<sf::Sprite>> sprites;
    void loadTextures( const std::string &path );
    void loadSprites( float scale = 1.f);
};


#endif //DEFENCETOWER_ENEMYFLYWEIGHT_H
