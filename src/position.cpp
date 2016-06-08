#include "position.hpp"

Position::Position(int x, int y) : mX(x), mY(y) {
}

int Position::x() { return mX; }

int Position::y() { return mY; }

void Position::move(int x, int y) {
  mX += x;
  mY += y;
}
