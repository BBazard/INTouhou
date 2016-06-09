#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class Sprite {
 private:
  static std::map<std::string, sf::Texture> mPoolTexture;
  static std::map<std::string, sf::Sprite> mPoolSprite;
  sf::Sprite *mSprite;
  //sf::Texture mTexture;

 public:
  Sprite(const std::string &img);
  sf::Sprite& getSprite(float x, float y);
};

