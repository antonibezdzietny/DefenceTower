#include <SFML/Graphics.hpp>
#include "include/EnemyFlyweightRed.h"
#include "include/EnemyFlyweightFactory.h"

int main()
{
    EnemyFlyweightFactory eff;
    EnemyFlyweight *b = eff.getEnemyFlyweight(EnemyFlyweightFactory::EnemyGreen);

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        sf::Sprite a = b->getSprite(EnemyFlyweight::WALK, 0);
        a.setPosition(200,200);
        window.draw(a);
        window.display();
    }

    return 0;
}