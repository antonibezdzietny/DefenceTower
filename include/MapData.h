//
// Created by muntek on 22.03.24.
//

#ifndef DEFENCETOWER_MAPDATA_H
#define DEFENCETOWER_MAPDATA_H

#include <vector>
#include <SFML/Graphics.hpp>

class MapData {
public:
    enum Type
    {
        MAP_0 = 0,
        MAP_1,
        MAP_2,
    };

private:
    /* Private fields */
    MapData::Type map_type_;
    std::vector<double>x_route_param_;
    std::vector<double>y_route_param_;

    /* Private methods */
    void loadMapParameters();
public:
    explicit MapData(MapData::Type type);
    ~MapData();
    [[nodiscard]] float getRoutePositionX(float n) const;
    [[nodiscard]] float getRoutePositionY(float n) const;
    [[nodiscard]] sf::Vector2f getRoutePosition(float n) const;
};


#endif //DEFENCETOWER_MAPDATA_H
