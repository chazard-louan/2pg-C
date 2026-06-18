//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_INPUT_H
#define MYGAME_INPUT_H
#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <unordered_map>


class InputManager {
public:
    void handleEvent(const sf::Event& event);

    bool isKeyDown(sf::Keyboard::Key key) const;

private:
    std::unordered_map<sf::Keyboard::Key, bool> keys;
};
#endif //MYGAME_INPUT_H
