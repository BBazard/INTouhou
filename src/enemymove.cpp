#include "enemymove.hpp"
#include <iostream>
#include "world.hpp"

EnemyMove::EnemyMove() {
}

void EnemyMove::run(World &world) {
  static bool right = right;
  for (size_t i = 0; i < world.getBitset(SHOOT).size(); ++i) {
    if (world.getBitset(SHOOT)[i]) {
      world.getDynamic(i).moveH(world.getPosition(i), right);

      auto& s = world.getSprite(i);
      auto& pos = world.getPosition(i);

      // enemy changes direction
      if (pos.x() < 0)
        right = true;

      else if (pos.x() > WINDOW_WIDTH - s.getSizeX())
        right = false;
    }
  }
}
