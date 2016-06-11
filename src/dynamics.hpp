#pragma once

#include "position.hpp"

class Dynamics {
 private:
  float mSpeed;
  // int mAccel;

 public:
  Dynamics();
  void move(Position& pos);
};
