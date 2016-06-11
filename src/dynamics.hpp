#pragma once

#include "position.hpp"

class Dynamics {
 private:
  int mSpeed;
  // int mAccel;

 public:
  Dynamics();
  void move(Position& pos);
};
