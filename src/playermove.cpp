#include "playermove.hpp"
#include "world.hpp"

PlayerMove::PlayerMove() {
}

void PlayerMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(EVENT).size(); ++i) {
    if (world.getBitset(EVENT)[i]) {
      if (world.getEvent(i).getMove()[LEFT] == true) {
        if (world.getPositions()[i].x() - 5 < 0)
         world.getPositions()[i].setX(0);
        else
          world.getPositions()[i].move(-5, 0);
      }
      if (world.getEvent(i).getMove()[RIGHT] == true) {
        if (world.getPositions()[i].x() + 5 > WINDOW_WIDTH - world.getSprites()[i].getSizeX())
          world.getPositions()[i].setX(WINDOW_WIDTH - world.getSprites()[i].getSizeX());
        else
          world.getPositions()[i].move(5, 0);
      }
      if (world.getEvent(i).getMove()[UP] == true) {
        if (world.getPositions()[i].y() - 5 < 0)
          world.getPositions()[i].setY(0);
        else
          world.getPositions()[i].move(0, -5);
      }
      if (world.getEvent(i).getMove()[DOWN] == true) {
        if (world.getPositions()[i].y() + 5 > WINDOW_HEIGHT - world.getSprites()[i].getSizeY())
          world.getPositions()[i].setY(WINDOW_HEIGHT - world.getSprites()[i].getSizeY());
        else
          world.getPositions()[i].move(0, 5);
      }
    }
  }
}
