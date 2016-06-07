#pragma once
#include <system.hpp>
#include <SFML/Graphics.hpp>

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
  sf::Sprite mSpriteBackground;
  sf::Texture mTextureBackground;

 public:
  Display();
  void run() override;
};
