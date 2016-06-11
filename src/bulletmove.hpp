#pragma once
#include "system.hpp"

class BulletMove : public System {
 public:
  BulletMove();
  void run(World &world);
};

