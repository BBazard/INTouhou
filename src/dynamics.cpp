#include "dynamics.hpp"
#include "position.hpp"

Dynamics::Dynamics() : mSpeedBulletPlayer(10), mSpeedEnemy(1) {
}

void Dynamics::moveV(Position& pos) {
  pos.move(0, -mSpeedBulletPlayer);
}

/**
 * @brief Dynamics::moveV2
 * @todo change this fonction to make good bullet pattern
 */
void Dynamics::moveV2(Position& pos) {
  pos.move(0, mSpeedBulletPlayer);
}



void Dynamics::moveH(Position& pos, bool right) {
  if (right)
    pos.move(mSpeedEnemy, 0);
  else
    pos.move(-mSpeedEnemy, 0);
}
