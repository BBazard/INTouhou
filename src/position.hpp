#pragma once
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800


class Position {
 private:
  int mX;
  int mY;
 public:
  Position(int x, int y);
  void move(int x, int y);
  void setX(int x);
  void setY(int y);
  int x();
  int y();
};
