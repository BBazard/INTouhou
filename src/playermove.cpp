#include "playermove.hpp"
#include "world.hpp"

PlayerMove::PlayerMove() {
}

void PlayerMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(EVENT).size(); ++i) {
    int LIMIT_WIDTH = WINDOW_WIDTH - world.getSprites(i).getSizeX();
    int LIMIT_HEIGHT = WINDOW_HEIGHT - world.getSprites(i).getSizeY();
    if (world.getBitset(EVENT)[i]) {
      if (world.getEvent(i).getMove()[LEFT] == true) {
        if (world.getPositions(i).x() - 5 < 0)
         world.getPositions(i).setX(0);
        else
          world.getPositions(i).move(-5, 0);
      }
      if (world.getEvent(i).getMove()[RIGHT] == true) {
        if (world.getPositions(i).x() + 5 > LIMIT_WIDTH)
          world.getPositions(i).setX(LIMIT_WIDTH);
        else
          world.getPositions(i).move(5, 0);
      }
      if (world.getEvent(i).getMove()[UP] == true) {
        if (world.getPositions(i).y() - 5 < 0)
          world.getPositions(i).setY(0);
        else
          world.getPositions(i).move(0, -5);
      }
      if (world.getEvent(i).getMove()[DOWN] == true) {
        if (world.getPositions(i).y() + 5 > LIMIT_HEIGHT)
          world.getPositions(i).setY(LIMIT_HEIGHT);
        else
          world.getPositions(i).move(0, 5);
      }
    }
  }
}
