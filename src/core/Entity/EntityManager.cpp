//
// Created by louan on 18/06/2026.
//

#include "EntityManager.hpp"

void EntityManager::add(std::unique_ptr<Entity> entity)
{
    entities.push_back(std::move(entity));
}

std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities()
{
    return entities;
}
