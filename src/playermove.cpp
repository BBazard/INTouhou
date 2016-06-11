#include "playermove.hpp"
#include "world.hpp"

PlayerMove::PlayerMove() {
}

void PlayerMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(EVENT).size(); ++i) {
    int LIMIT_WIDTH = WINDOW_WIDTH - world.getSprite(i).getSizeX();
    int LIMIT_HEIGHT = WINDOW_HEIGHT - world.getSprite(i).getSizeY();
    if (world.getBitset(EVENT)[i]) {
      if (world.getEvent(i).getMove()[LEFT] == true) {
        if (world.getPosition(i).x() - 5 < 0)
         world.getPosition(i).setX(0);
        else
          world.getPosition(i).move(-5, 0);
      }
      if (world.getEvent(i).getMove()[RIGHT] == true) {
        if (world.getPosition(i).x() + 5 > LIMIT_WIDTH)
          world.getPosition(i).setX(LIMIT_WIDTH);
        else
          world.getPosition(i).move(5, 0);
      }
      if (world.getEvent(i).getMove()[UP] == true) {
        if (world.getPosition(i).y() - 5 < 0)
          world.getPosition(i).setY(0);
        else
          world.getPosition(i).move(0, -5);
      }
      if (world.getEvent(i).getMove()[DOWN] == true) {
        if (world.getPosition(i).y() + 5 > LIMIT_HEIGHT)
          world.getPosition(i).setY(LIMIT_HEIGHT);
        else
          world.getPosition(i).move(0, 5);
      }
    }
  }
}
