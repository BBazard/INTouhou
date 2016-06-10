#include "dynamics.hpp"
#include "position.hpp"

Dynamics::Dynamics() : mSpeed(10) {
}

Position Dynamics::move(int x, int y) {
  return Position(x, y-mSpeed);
}

