#include "position.hpp"
#include <iostream>

Position::Position(int x, int y) : mX(x), mY(y) {
}

int Position::x() { return mX; }

int Position::y() { return mY; }

/**
 * @brief Relative move
 * @todo To disallow moves outside the window
 */
void Position::move(int x, int y) {
 std::cout << "BeforeMove: " << mY << std::endl;
  mX += x;
  mY += y;
 std::cout << "AfterMove: " << mY << std::endl;
}
