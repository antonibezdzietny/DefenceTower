#ifndef DEFENCETOWER_ENEMYRED_H
#define DEFENCETOWER_ENEMYRED_H

#include "Enemy.h"
#include "EnemyFlyweightFactory.h"

class EnemyRed : public  Enemy{

public:
    explicit  EnemyRed(EnemyRoute &route, EnemyFlyweightFactory& eff, sf::Vector2f position = sf::Vector2f(0.f, 0.f));
    ~EnemyRed();
};


#endif //DEFENCETOWER_ENEMYRED_H
