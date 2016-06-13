#pragma once
#include "system.hpp"

class CreateEnemyBullet {
 private:
  int mLastTime;
 public:
  CreateEnemyBullet();
  void run(World &world);
};
