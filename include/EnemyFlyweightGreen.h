//
// Created by muntek on 20.03.24.
//

#ifndef DEFENCETOWER_ENEMYFLYWEIGHTGREEN_H
#define DEFENCETOWER_ENEMYFLYWEIGHTGREEN_H

#include "../include/EnemyFlyweight.h"
#include "string"

class EnemyFlyweightGreen : public EnemyFlyweight{
    inline const static std::string TEXTURE_PATH = "texture/enemy/green";
    inline const static float  SCALE = 0.3f;

public:
    EnemyFlyweightGreen() : EnemyFlyweight(TEXTURE_PATH, SCALE){};
    ~EnemyFlyweightGreen() = default;
};


#endif //DEFENCETOWER_ENEMYFLYWEIGHTGREEN_H
