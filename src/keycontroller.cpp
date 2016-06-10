#include "keycontroller.hpp"
#include <iostream>
#include "world.hpp"

KeyController::KeyController(sf::RenderWindow &window) : mWindow(window) {
}

void KeyController::run(World &world) {
    while (mWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        mWindow.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        mWindow.close();
      if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up)) {
      world.getEvent(0).pushDirection(UP);
       }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      world.getEvent(0).pushDirection(DOWN);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      world.getEvent(0).pushDirection(LEFT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      world.getEvent(0).pushDirection(RIGHT);
  }
}
