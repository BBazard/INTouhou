#pragma once
#include <SFML/Graphics.hpp>
#include "component.hpp"
#include "position.hpp"

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
