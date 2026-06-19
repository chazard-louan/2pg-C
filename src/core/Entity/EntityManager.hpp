//
// Created by louan on 18/06/2026.
//

#ifndef MYGAME_ENTITYMANAGER_H
#define MYGAME_ENTITYMANAGER_H
#pragma once

#include <memory>
#include <vector>
#include "Entity.hpp"

class EntityManager {

public:
    void add(std::unique_ptr<Entity> entity);

    std::vector<std::unique_ptr<Entity>>& getEntities();
private:
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif //MYGAME_ENTITYMANAGER_H
