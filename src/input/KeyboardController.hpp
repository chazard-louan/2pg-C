//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_KEYBOARDCONTROLLER_H
#define MYGAME_KEYBOARDCONTROLLER_H
#pragma once
#include "Controller.hpp"
#include "InputManager.hpp"
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

class KeyboardController : public Controller {
public:
    explicit KeyboardController(const InputManager& input);

    void bind(Action action, sf::Keyboard::Key key);

    bool isActionDown(Action action) const override;

private:
    const InputManager& input;

    std::unordered_map<Action, sf::Keyboard::Key> bindings;
};
#endif //MYGAME_KEYBOARDCONTROLLER_H
