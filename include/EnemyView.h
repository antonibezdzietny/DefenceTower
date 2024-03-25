#ifndef DEFENCETOWER_ENEMYVIEW_H
#define DEFENCETOWER_ENEMYVIEW_H

#include <SFML/Graphics.hpp>
#include "EnemyFlyweight.h"

class EnemyView : public sf::Drawable{
    sf::Sprite* sprite_ = nullptr;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    EnemyView() = default;
    ~EnemyView() override = default;
    void setSprite(sf::Sprite* sprite);
};


#endif //DEFENCETOWER_ENEMYVIEW_H
