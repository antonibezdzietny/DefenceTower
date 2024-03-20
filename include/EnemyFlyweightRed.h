#ifndef DEFENCETOWER_ENEMYFLYWEIGHTRED_H
#define DEFENCETOWER_ENEMYFLYWEIGHTRED_H

#include "EnemyFlyweight.h"

class EnemyFlyweightRed : public EnemyFlyweight{
private:
    inline const static std::string TEXTURE_PATH = "texture/enemy/red";
    inline const static float  SCALE = 0.3f;
public:
    EnemyFlyweightRed() : EnemyFlyweight(TEXTURE_PATH, SCALE){};
    ~EnemyFlyweightRed() = default;
};


#endif //DEFENCETOWER_ENEMYFLYWEIGHTRED_H
