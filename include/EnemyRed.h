#ifndef DEFENCETOWER_ENEMYRED_H
#define DEFENCETOWER_ENEMYRED_H

#include "Enemy.h"

class EnemyRed : public  Enemy{

public:
    EnemyRed();
    ~EnemyRed();

    void onHit(int damage) override;
};


#endif //DEFENCETOWER_ENEMYRED_H
