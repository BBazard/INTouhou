#pragma once

#include "position.hpp"
#include "lagrange.hpp"

class Dynamics {
 private:
  Lagrange mLagrange;
  float mSpeedBulletPlayer;
  float mSpeedEnemy;
  // int mAccel;

 public:
  Dynamics();
  void moveV(Position& pos);
  void moveH(Position& pos, bool right);
  void moveV2(Position& pos);
  void genPol(std::vector<float> x, std::vector<float> y);
};
