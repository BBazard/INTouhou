#pragma once
#include "system.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "position.hpp"
#include "sprite.hpp"

/**
 * @brief Display the window
 *
 * Display a window with 2 views, one for the game, the second for the score
 *
 */
class Display : public System {
 private:
  sf::RenderWindow mWindow;
  sf::View mViewScore;
  sf::View mViewGame;
  Sprite mSpriteBackground;
//  sf::Texture mTextureBackground;
  Sprite mVaisseau;

  sf::Text mScoreText;
  sf::Font f;

  int mScore = 500000;

 public:
  Display();
  void run(World &world) override;
};
