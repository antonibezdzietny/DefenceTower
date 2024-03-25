#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "include/EnemyFlyweightRed.h"
#include "include/EnemyFlyweightFactory.h"
#include "include/EnemyView.h"
#include "include/EnemyRed.h"
#include "include/Enemy.h"
#include "include/EnemyRoute.h"
#include <json.hpp>
#include <fstream>
#include "include/MapData.h"


using json = nlohmann::json;

int main()
{
    MapData mapData(MapData::MAP_0);
    float counter = 0.0;



    std::fstream f("datasets/map/map_00.json");
    json data = json::parse(f);

    std::vector<double> bb;
    bb.insert(bb.end(), data["x_function"].begin(), data["x_function"].end());

    EnemyFlyweightFactory eff;
    EnemyFlyweight *b = eff.getEnemyFlyweight(EnemyFlyweightFactory::EnemyGreen);
    EnemyView ev;
    EnemyRoute erout;

    EnemyRed enemyRed(erout, eff, sf::Vector2f(200.f, 200.f));
    sf::Texture map_tx;
    map_tx.loadFromFile("./texture/map/map_00.jpeg");
    sf::Sprite map_sp;
    map_sp.setTexture(map_tx);


    sf::RenderWindow window(sf::VideoMode(map_tx.getSize().x, map_tx.getSize().y), "SFML works!");
    window.setFramerateLimit(30);
    sf::Clock clock;
    clock.restart();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(map_sp);

        counter += 0.001;
        sf::Vector2f pos = mapData.getRoutePosition(counter);
        enemyRed.setPosition(pos);
        enemyRed.setState(WALK);

        enemyRed.update(clock.restart().asMilliseconds(), ev);

        window.draw(ev);
        window.display();
    }

    return 0;
}