#include "sprite.hpp"
#include <iostream>
#include <map>
#include <string>

std::map<std::string, sf::Texture> Sprite::mPoolTexture;
std::map<std::string, sf::Sprite> Sprite::mPoolSprite;

Sprite::Sprite(const std::string &img) {
  if (mPoolTexture.insert(std::make_pair(img, sf::Texture())).second) {
    if (!mPoolTexture[img].loadFromFile(img))
      std::cout << "erreur" << std::endl;
    mPoolSprite.insert(std::make_pair(img, sf::Sprite()));
    mPoolSprite[img].setTexture(mPoolTexture[img]);
  }
  mSprite = &(mPoolSprite[img]);
}

sf::Sprite& Sprite::getSprite(float x, float y) {
  mSprite->setPosition(x, y);
  return *mSprite;
}

