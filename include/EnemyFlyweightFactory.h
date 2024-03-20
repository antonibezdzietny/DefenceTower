#include "unordered_map"
#include "EnemyFlyweight.h"

#ifndef DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H
#define DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H


class EnemyFlyweightFactory {
public:
    enum EnemyType
    {
        EnemyRed = 0,
        EnemyGreen,
    };
    EnemyFlyweightFactory() = default;
    ~EnemyFlyweightFactory();


private:
    std::unordered_map<EnemyFlyweightFactory::EnemyType, EnemyFlyweight*> flyweights;

public:
    EnemyFlyweight* getEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type);
    void loadEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type);
    void clearEnemyFlyweight();
    void clearEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type);
};


#endif //DEFENCETOWER_ENEMYFLYWEIGHTFACTORY_H
