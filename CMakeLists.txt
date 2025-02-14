cmake_minimum_required(VERSION 3.27)
project(DefenceTower)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(DefenceTower main.cpp
        src/Enemy.cpp
        include/Enemy.h
        src/EnemyFlyweightFactory.cpp
        include/EnemyFlyweightFactory.h
        src/EnemyFlyweight.cpp
        include/EnemyFlyweight.h
        include/EnemyFlyweightRed.h
        include/EnemyFlyweightGreen.h
        include/EnemyState.h
        src/EnemyRed.cpp
        include/EnemyRed.h
        src/EnemyView.cpp
        include/EnemyView.h
        include/EnemyRoute.h
        src/MapData.cpp
        include/MapData.h
)

add_library(json INTERFACE)
target_include_directories(json INTERFACE libs)

target_link_libraries(DefenceTower sfml-graphics json)