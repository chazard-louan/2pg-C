cmake_minimum_required(VERSION 3.2)
project(MyGame)

set(CMAKE_CXX_STANDARD 23)
file(GLOB_RECURSE SOURCES

        "src/*.cpp"
        "include/*.h"
)
find_package(SFML 2 REQUIRED COMPONENTS graphics)

add_executable(MyGame
        ${SOURCES}
)

target_link_libraries(MyGame PRIVATE sfml-graphics)

target_include_directories(MyGame PRIVATE include)
