//
// Created by louan on 18/06/2026.
//
#include "KeyboardController.hpp"

KeyboardController::KeyboardController(const InputManager& input)
    : input(input)
{}

void KeyboardController::bind(Action action, sf::Keyboard::Key key) {
    bindings[action] = key;
}

bool KeyboardController::isActionDown(const Action action) const {
    const auto it = bindings.find(action);
    if (it == bindings.end())
        return false;

    return input.isKeyDown(it->second);
}