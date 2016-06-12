#include "dynamics.hpp"
#include "position.hpp"

Dynamics::Dynamics() : mSpeedBulletPlayer(10), mSpeedEnemy(1) {
}

void Dynamics::moveV(Position& pos) {
  pos.move(0, -mSpeedBulletPlayer);
}


void Dynamics::moveH(Position& pos, bool right) {
  if (right)
    pos.move(mSpeedEnemy, 0);
  else
    pos.move(-mSpeedEnemy, 0);
}
