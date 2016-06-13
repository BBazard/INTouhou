#pragma once
#include "component.hpp"
#include "position.hpp"
#include <SFML/Graphics.hpp>

class Hitbox {
 private:
  sf::RectangleShape mHitbox;
  int mX;
  int mY;
 public:
  Hitbox();
  void setSize(int w, int h);
  void setPosition(Position pos);
  void setShift(int x, int y);
  int x();
  int y();
  int w();
  int h();
  sf::RectangleShape& getHitbox();
};
