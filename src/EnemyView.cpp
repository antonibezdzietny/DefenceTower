

#include "../include/EnemyView.h"
#include "../include/EnemyFlyweightFactory.h"


void EnemyView::setSprite(sf::Sprite* sprite) {sprite_ = sprite;}

void EnemyView::draw(sf::RenderTarget &target, sf::RenderStates states) const{target.draw(*sprite_, states);}


