#include "display.hpp"
#include <iostream>
#include "world.hpp"

/**
 * @brief
 *
 * @todo exceptions
 */
Display::Display(sf::RenderWindow &w) :
  mWindow(w),
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
  mScoreText.setColor(sf::Color::Blue);

  mLifeText.setFont(f);
  mLifeText.setPosition(sf::Vector2f(500, 20));
  mLifeText.setColor(sf::Color::Blue);
}

void Display::run(World &world) {
  mWindow.clear(sf::Color::Black);
  mWindow.setView(mViewScore);
  std::ostringstream tmpScore;
  std::ostringstream tmpLife;
  tmpScore << "Score: " << world.getScore();
  mScoreText.setString(tmpScore.str());
  mWindow.draw(mScoreText);
  tmpLife << "Life: " << world.getLife(0).getLife();
  mLifeText.setString(tmpLife.str());
  mWindow.draw(mLifeText);
  mWindow.setView(mViewGame);
  mWindow.draw(mSpriteBackground.getSprite(0.0, 0.0));
  for (size_t i = 0; i < world.getBitset(SPRITE).size(); ++i) {
    if (world.getBitset(SPRITE)[i]) {
      float X = world.getPosition(i).x();
      float Y = world.getPosition(i).y();
      mWindow.draw(world.getSprite(i).getSprite(X, Y));
    }
  }
  if (world.getLife(0).getLife() == 0) {
    sf::Text loseText("\t\tYOU LOSE\n\n Press escape to quit", f);
    loseText.setPosition(150, 300);
    loseText.setColor(sf::Color::Red);
    mWindow.draw(loseText);
  }
  mWindow.display();
}
