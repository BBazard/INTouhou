#pragma once

#include "position.hpp"

class Dynamics {
 private:
  float mSpeedBulletPlayer;
  float mSpeedEnemy;
  // int mAccel;

 public:
  Dynamics();
  void moveV(Position& pos);
  void moveH(Position& pos, bool right);
};
