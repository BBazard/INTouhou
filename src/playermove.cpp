#include "playermove.hpp"
#include "world.hpp"

PlayerMove::PlayerMove()
{

}

void PlayerMove::run(World &world) {
  for (size_t i = 0; i < world.getBitset(EVENT).size(); ++i) {
    Direction test = world.getEvent(i).popDirection();
    if (world.getBitset(EVENT)[i]) {
      if(test == LEFT)
        world.getPositions()[i].move(-10, 0);
      if(test == RIGHT)
        world.getPositions()[i].move(10, 0);
      if(test == UP)
        world.getPositions()[i].move(0, -10);
      if(test == DOWN)
        world.getPositions()[i].move(0, 10);
    }
  }
}
