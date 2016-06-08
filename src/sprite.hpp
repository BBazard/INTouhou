#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "position.hpp"

class Sprite {
 private:
  sf::Sprite mSprite;
  sf::Texture mTexture;

 public:
  explicit Sprite(std::string img);
  sf::Sprite getSprite();
  void setPosition(Position pos);
};
