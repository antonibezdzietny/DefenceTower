#include "unordered_map"
#include "EnemyType.h"
#include "EnemyFlyweight.h"

#ifndef DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H
#define DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H


class EnemyFlyweightFactory {
    std::unordered_map<EnemyType, EnemyFlyweight> flyweights_;


private:


public:
    EnemyFlyweight getEnemyFlyweight(EnemyType enemy_type);
    void loadEnemyFlyweight(EnemyType *enemy_types);
};


#endif //DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H
