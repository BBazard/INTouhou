#include "position.hpp"

Position::Position(int x, int y) : mX(x), mY(y) {
}

int Position::x() { return mX; }

int Position::y() { return mY; }

/**
 * @brief Relative move
 */
void Position::move(int x, int y) {
  mX += x;
  mY += y;
}

void Position::setX(int x) {
  mX = x;
}

void Position::setY(int y) {
  mY = y;
}
