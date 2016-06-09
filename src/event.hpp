#pragma once
#include <queue>

typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NONE,
} Direction;

class Event {
 private:
  std::queue<Direction> mMove;

 public:
  Event();
  void pushDirection(Direction dir);
  Direction popDirection();
};
