#pragma once

#include "component.hpp"

class Target {
 private:
  TargetType mTargetType;
  //  int mAccel;

 public:
  Target(TargetType &tt);
  TargetType getTarget();
};

