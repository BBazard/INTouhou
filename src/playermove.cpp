#include "playermove.hpp"
#include "world.hpp"

PlayerMove::PlayerMove() {
}

void PlayerMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(EVENT).size(); ++i) {
    if (world.getBitset(EVENT)[i]) {
      if (world.getEvent(i).getMove()[LEFT] == true)
        world.getPositions()[i].move(-5, 0);
      if (world.getEvent(i).getMove()[RIGHT] == true)
        world.getPositions()[i].move(5, 0);
      if (world.getEvent(i).getMove()[UP] == true)
        world.getPositions()[i].move(0, -5);
      if (world.getEvent(i).getMove()[DOWN] == true)
        world.getPositions()[i].move(0, 5);
    }
  }
}
