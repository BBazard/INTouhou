#pragma once
#include <vector>
#include "component.hpp"

class Event {
 private:
//  std::queue<Direction> mMove;
  std::vector<bool> mMove;

 public:
  Event();
  void pushDirection(Direction dir);
  void popDirection(Direction dir);
  std::vector<bool> getMove();
};
