#pragma once
#include "system.hpp"


class EnemyMove : public System {
 public:
  EnemyMove();
  void run(World &world);
};
