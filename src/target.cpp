#include "target.hpp"
#include "position.hpp"

Target::Target(TargetType& tt) : mTargetType(tt) {
}

TargetType Target::getTarget() {
  return mTargetType;
}

