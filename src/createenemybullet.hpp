#pragma once
#include "system.hpp"

class CreateEnemyBullet {
 private:
  int mLastTime;
  int mTimeBetweenBullet;
 public:
  CreateEnemyBullet();
  void run(World &world);
};
