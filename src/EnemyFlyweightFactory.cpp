//
// Created by muntek on 19.03.24.
//

#include "../include/EnemyFlyweightFactory.h"
#include "../include/EnemyFlyweightRed.h"
#include "../include/EnemyFlyweightGreen.h"

EnemyFlyweightFactory::~EnemyFlyweightFactory() {
    clearEnemyFlyweight();
}

EnemyFlyweight* EnemyFlyweightFactory::getEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type)
{
    // If enemy type is in memory -> return
    if( flyweights.find(enemy_type) != flyweights.end() )
        return flyweights.at(enemy_type);


    // If enemy type not in memory -> load to memory & return
    loadEnemyFlyweight(enemy_type);
    return flyweights.at(enemy_type);
}

void EnemyFlyweightFactory::loadEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type)
{
    switch (enemy_type) {
        case EnemyType::EnemyRed:
            flyweights.insert(std::make_pair(enemy_type, new EnemyFlyweightRed()));
            break;
        case EnemyType::EnemyGreen:
            flyweights.insert(std::make_pair(enemy_type, new EnemyFlyweightGreen()));
            break;
    }
}

void EnemyFlyweightFactory::clearEnemyFlyweight()
{
    for (auto & pair : flyweights)
        delete pair.second;
    flyweights.clear();
}

void EnemyFlyweightFactory::clearEnemyFlyweight(EnemyFlyweightFactory::EnemyType enemy_type)
{
    auto search = flyweights.find(enemy_type);
    if ( search == flyweights.end() )
        return; // Enemy not found in set

    // Delete form data set
    delete search->second;
    flyweights.erase(search);
}


