#include "../include/Enemy.h"
#include <iostream>

Enemy::Enemy(EnemyRoute& route, EnemyFlyweightFactory& eff){
    eff_             = eff;
    route_           = route;
    position_        = sf::Vector2f(0.f, 0.f);
    state_           = EnemyState::IDLE;
    state_waiting_   = EnemyState::IDLE;
    health_          = 100;
    speed_walk_      = 1;
    n_texture_frame_ = 0;
    total_time_      = 1000;
    switch_time_     = 50;
}

Enemy::~Enemy() {

}

void Enemy::update(int32_t deltaT, EnemyView &ev) {
    total_time_ += deltaT;

    if(total_time_ < switch_time_)
        return; // If switch time not yet


    total_time_ = 0;
    n_texture_frame_ = (++n_texture_frame_)%EnemyFlyweight::N_TEXTURES_PER_TYPE;

    if(n_texture_frame_ == 0)
        state_ = state_waiting_;

    sf::Sprite *sp = eff_.getEnemyFlyweight(EnemyFlyweightFactory::EnemyRed)
            ->getSprite(state_, n_texture_frame_);
    sp->setPosition(position_);
    ev.setSprite(sp);
}

void Enemy::hit(int damage) { health_ -= damage; }

void Enemy::setPosition(float x, float y){ setPosition( sf::Vector2(x,y) ); }

void Enemy::setPosition(sf::Vector2f position) { position_ = position; }

sf::Vector2f Enemy::getPosition() { return position_; }

void Enemy::setState(EnemyState state) { state_waiting_ = state; }

EnemyState Enemy::getState() { return state_; }

bool Enemy::isAlive() const { return health_ > 0; }



