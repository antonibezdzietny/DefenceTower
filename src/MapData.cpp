#include "../include/MapData.h"

#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <json.hpp>
#include <cmath>
#include <iostream>

MapData::MapData(MapData::Type type) {
    map_type_ = type;
    loadMapParameters();
}

MapData::~MapData() = default;

void MapData::loadMapParameters() {
    // Create path to json file
    std::string default_path = "datasets/map/map_";
    std::ostringstream oss;
    oss << default_path << std::setfill('0') << std::setw(2) << map_type_ << ".json";
    std::fstream json_file(oss.str());

    // Parse json data
    using json = nlohmann::json;
    json json_data = json::parse(json_file);
    json_file.close();

    // Load route param
    x_route_param_.insert(x_route_param_.end(),
                          json_data["x_function"].begin(),
                          json_data["x_function"].end());
    y_route_param_.insert(y_route_param_.end(),
                          json_data["y_function"].begin(),
                          json_data["y_function"].end());
}

float MapData::getRoutePositionX(float n) const
{
    double x_position = 0.;
    for (int i = 0; i <= x_route_param_.size(); ++i)
        x_position += x_route_param_[i] * pow(n, (x_route_param_.size() - (i + 1)));

    std::cout << "n: " << n << std::endl;
    std::cout << "x: " << x_position << std::endl;
    return (float)x_position;
}

float MapData::getRoutePositionY(float n) const
{
    double y_position = 0.;
    for (int i = 0; i <= y_route_param_.size(); ++i)
        y_position += y_route_param_[i] * pow(n, (y_route_param_.size() - (i + 1)));

    std::cout << "y: " << y_position << std::endl;
    return (float)y_position;
}

sf::Vector2f MapData::getRoutePosition(float n) const {
    return {getRoutePositionX(n), getRoutePositionY(n)};
}

