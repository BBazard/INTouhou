#include <iostream>
#include "display.hpp"

/**
 * @brief
 *
 * @todo exceptions
 */
Display::Display() : mWindow(sf::VideoMode(600, 800), "INTouhou") {
  int width = mWindow.getSize().x;
  int height = mWindow.getSize().y;
  float proportion = 0.1;

  mViewScore.reset(sf::FloatRect(0, 0, width, height * proportion));
  mViewScore.setViewport(sf::FloatRect(0.f, 0.9f, 1.f, 0.1f));

  mViewGame.reset(sf::FloatRect(0, 0, width, height));
  mViewGame.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f - proportion));

  if (!mTextureBackground.loadFromFile("background.png"))
    std::cout << "erreur" << std::endl;
  // Exception if the file hasn't been load

  mSpriteBackground.setTexture(mTextureBackground);
}

void Display::run() {
  while (mWindow.isOpen()) {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        mWindow.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        mWindow.close();
    }

    mWindow.clear(sf::Color::Black);
    mWindow.setView(mViewScore);
    /* Add the score */
    mWindow.setView(mViewGame);
    mWindow.draw(mSpriteBackground);
    mWindow.display();
  }
}
