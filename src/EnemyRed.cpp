#include "../include/EnemyRed.h"

EnemyRed::EnemyRed(EnemyRoute &route, EnemyFlyweightFactory& eff, sf::Vector2f position) : Enemy(route, eff) {
 position_        = position;
    state_           = EnemyState::IDLE;
    health_          = 100;
    speed_walk_      = 1;
    n_texture_frame_ = 0;
}

EnemyRed::~EnemyRed() {

}



