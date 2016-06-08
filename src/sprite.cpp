#include "sprite.hpp"
#include <string>

Sprite::Sprite(std::string img) {
  if (!mTexture.loadFromFile(img))
    std::cout << "erreur" << std::endl;

  mSprite.setTexture(mTexture);
}

sf::Sprite Sprite::getSprite() {
  return mSprite;
}

void Sprite::setPosition(Position pos) {
  mSprite.setPosition(pos.x(), pos.y());
}
