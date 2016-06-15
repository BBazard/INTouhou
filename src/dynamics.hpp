#pragma once

#include "position.hpp"
#include "lagrange.hpp"
#include "component.hpp"

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
  void movePattern(Position& pos);
  void genPattern(Position &from, Position &to, PatternType pt);

 private:
  void genPol(std::vector<float> x, std::vector<float> y);
};
