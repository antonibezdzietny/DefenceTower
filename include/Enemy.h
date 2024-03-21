//
// Created by muntek on 19.03.24.
//

#ifndef DEFENCETOWER_ENEMY_H
#define DEFENCETOWER_ENEMY_H

#include <SFML/Graphics.hpp>
#include "EnemyState.h"

class Enemy {
    sf::Vector2f position_;
    EnemyState state_;
    int n_texture_frame_;
    int16_t health_;
    uint16_t speed_walk_;
    uint16_t speed_run_;
    uint16_t armor_;
public:
    Enemy();
    ~Enemy();

    virtual void onHit(int damage) = 0;


    // Setters
    void setState(EnemyState state);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);

    // Getters
    EnemyState getState();
    sf::Vector2f getPosition();
    [[nodiscard]] bool isAlive() const;
};


#endif //DEFENCETOWER_ENEMY_H
