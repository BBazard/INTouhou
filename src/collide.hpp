#pragma once
#include "system.hpp"

class Collide : public System {
 public:
  Collide();
  void run(World &world);
};
