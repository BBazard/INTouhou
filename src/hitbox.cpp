#include "hitbox.hpp"

Hitbox::Hitbox() {
}

void Hitbox::setPosition(Position pos) {
  mHitbox.setPosition(pos.x(), pos.y());
}

sf::RectangleShape &Hitbox::getHitbox() {
  return mHitbox;
}

void Hitbox::setSize(int w, int h) {
  mHitbox.setSize(sf::Vector2f(w, h));
}

void Hitbox::setShift(int x, int y) {
  mX = x;
  mY = y;
}

int Hitbox::x() {
  return mHitbox.getPosition().x + mX/2;
}

int Hitbox::y() {
  return mHitbox.getPosition().y + mY/2;
}

int Hitbox::w() {
  return mHitbox.getSize().x - mX;
}

int Hitbox::h() {
  return mHitbox.getSize().y - mY;
}
