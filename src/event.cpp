#include "event.hpp"
#include <vector>
#include <iostream>
#include "component.hpp"

Event::Event() {
  mMove = std::vector<bool>(5, false);
}

void Event::pushDirection(Direction dir) {
  mMove[dir] = true;
}

void Event::popDirection(Direction dir) {
  mMove[dir] = false;
}

std::vector<bool> Event::getMove() {
  return mMove;
}
