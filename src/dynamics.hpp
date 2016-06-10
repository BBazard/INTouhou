#pragma once

#include "position.hpp"

class Dynamics {
 private:
  int mSpeed;
  //int mAccel;
  
 public:
  Dynamics();
  Position move(int x, int y);
};

