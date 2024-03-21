//
// Created by muntek on 19.03.24.
//

#include "../include/Enemy.h"

Enemy::Enemy() {
    position_        = sf::Vector2f(0.f, 0.f);
    state_           = EnemyState::IDLE;
    n_texture_frame_ = 0;
}

Enemy::~Enemy() {

}

void Enemy::setPosition(float x, float y){setPosition( sf::Vector2(x,y) );}

void Enemy::setPosition(sf::Vector2f position) { position_ = position;}

sf::Vector2f Enemy::getPosition() {return position_;}

void Enemy::setState(EnemyState state) {state_ = state;}

EnemyState Enemy::getState() {return state_;}

bool Enemy::isAlive() const {return health_ > 0;}

