#include <iostream>
#include "world.hpp"
#include "display.hpp"

/**
 * @brief
 *
 * @todo exceptions
 */
Display::Display() :
  mWindow(sf::VideoMode(600, 800), "INTouhou"),
  mSpriteBackground("../sprite/background.png"),
  mVaisseau("../sprite/vaisseau.png") {
  int width = mWindow.getSize().x;
  int height = mWindow.getSize().y;
  float proportion = 0.1;

  mViewScore.reset(sf::FloatRect(0, 0, width, height * proportion));
  mViewScore.setViewport(sf::FloatRect(0.f, 0.9f, 1.f, 0.1f));

  mViewGame.reset(sf::FloatRect(0, 0, width, height));
  mViewGame.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f - proportion));

  f.loadFromFile("../sprite/arial.ttf");
  mScoreText.setFont(f);
  mScoreText.setPosition(sf::Vector2f(10, 20));
  mScoreText.setColor(sf::Color::Red);
}

void Display::run(World &world) {
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
    std::ostringstream score;
    score << mScore;
    mScoreText.setString(score.str());
    mWindow.draw(mScoreText);
    mWindow.setView(mViewGame);
    mWindow.draw(mSpriteBackground.getSprite(0.0, 0.0));

    for (size_t i = 0; i < world.getBitset(SPRITE).size(); ++i) {
      if (world.getBitset(SPRITE)[i]) {
        float X = world.getPositions()[i].x();
        float Y = world.getPositions()[i].y();
        mWindow.draw(world.getSprites()[i].getSprite(X, Y));
      }
    }
       mWindow.display();
  }
}
