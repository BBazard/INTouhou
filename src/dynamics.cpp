#include "dynamics.hpp"
#include "position.hpp"

Dynamics::Dynamics() : mSpeed(10) {
}

void Dynamics::move(Position& pos) {
  pos.move(0, -mSpeed);
}

