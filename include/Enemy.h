#ifndef DEFENCETOWER_ENEMY_H
#define DEFENCETOWER_ENEMY_H

#include <SFML/Graphics.hpp>
#include "EnemyFlyweightFactory.h"
#include "EnemyState.h"
#include "EnemyRoute.h"
#include "EnemyView.h"

class Enemy {
protected:
    EnemyFlyweightFactory eff_;
    EnemyRoute route_;
    sf::Vector2f position_;
    EnemyState state_;
    EnemyState state_waiting_;
    int n_texture_frame_;
    int health_;
    int speed_walk_;

    int32_t total_time_;
    int32_t switch_time_;

public:
    explicit Enemy(EnemyRoute& route, EnemyFlyweightFactory& eff);
    virtual ~Enemy();


    void hit(int damage);
    void update(int32_t deltaT, EnemyView &ev);

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
