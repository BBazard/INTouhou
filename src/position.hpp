#pragma once

class Position {
 private:
  int mX;
  int mY;
 public:
  Position(int x, int y);
  void move(int x, int y);
  int x();
  int y();
};
