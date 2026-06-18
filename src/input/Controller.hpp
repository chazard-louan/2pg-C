//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_CONTROLLER_H
#define MYGAME_CONTROLLER_H
#pragma once
#include "Action.hpp"

class Controller {
public:
    virtual ~Controller() = default;

    virtual bool isActionDown(Action action) const = 0;
};
#endif //MYGAME_CONTROLLER_H
