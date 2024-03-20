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
)
target_link_libraries(DefenceTower sfml-graphics)