cmake_minimum_required(VERSION 3.16)
project(OriGearEngine VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

include_directories(include)

add_subdirectory(src)



find_package(SDL2 REQUIRED)
target_link_libraries(ogeg SDL2::Main)

find_package(SDL2_image REQUIRED)
target_link_libraries(ogeg SDL2::Image)

find_package(SDL2_ttf REQUIRED)
target_link_libraries(ogeg SDL2::TTF)

find_package(SDL2_mixer REQUIRED)
target_link_libraries(ogeg SDL2::Mixer)
