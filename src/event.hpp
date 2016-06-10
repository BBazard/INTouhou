#pragma once
#include <queue>
#include "component.hpp"

class Event {
 private:
  std::queue<Direction> mMove;

 public:
  Event();
  void pushDirection(Direction dir);
  Direction popDirection();
};
