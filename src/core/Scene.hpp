//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_SCENE_H
#define MYGAME_SCENE_H
#pragma once

#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
#endif //MYGAME_SCENE_H
