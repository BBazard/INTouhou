#include "hitbox.hpp"

Hitbox::Hitbox() {
}

void Hitbox::setPosition(Position pos) {
//  mHitbox.left = pos.x();
//  mHitbox.top = pos.y();
  mHitbox.setPosition(pos.x(), pos.y());
}

sf::RectangleShape &Hitbox::getHitbox() {
  return mHitbox;
}

void Hitbox::setSize(int w, int h) {
//  mHitbox.width = w;
//  mHitbox.height = h;
  mHitbox.setSize(sf::Vector2f(w, h));
}

void Hitbox::setShift(int x, int y) {
  mX = x;
  mY = y;
}
