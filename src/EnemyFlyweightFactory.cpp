//
// Created by muntek on 19.03.24.
//

#include "../include/EnemyFlyweightFactory.h"

EnemyFlyweight EnemyFlyweightFactory::getEnemyFlyweight(EnemyType enemy_type)
{
    if( flyweights_.find(enemy_type) == flyweights_.end() )
    {
        // If flyweights is not in memory
    }

    return flyweights_.at(enemy_type);
}

void EnemyFlyweightFactory::loadEnemyFlyweight(EnemyType *enemy_types)
{

}