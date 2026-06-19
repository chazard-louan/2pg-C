//
// Created by louan on 19/06/2026.
//

#ifndef MYGAME_ROPESYSTEM_H
#define MYGAME_ROPESYSTEM_H


#include "../../physics/PhysicsComponent.hpp"
#include "RopeComponent.hpp"



class RopeSystem
{
public:
  void update(PhysicsComponent& phys, RopeComponent& rope, float dt);

private:
  struct RopeBody
  {
    PhysicsComponent* physics;
    RopeComponent* rope;
  };

  std::vector<RopeBody> bodies;
};

#endif //MYGAME_ROPESYSTEM_H
