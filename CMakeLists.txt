cmake_minimum_required(VERSION 3.27)
project(DefenceTower)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(DefenceTower main.cpp)
target_link_libraries(DefenceTower sfml-graphics)