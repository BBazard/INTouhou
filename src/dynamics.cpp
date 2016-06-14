#include "dynamics.hpp"
#include "position.hpp"
#include "lagrange.hpp"
#include <vector>

Dynamics::Dynamics() : mSpeedBulletPlayer(10), mSpeedEnemy(1) {
}

void Dynamics::genPol(std::vector<float> x, std::vector<float> y) {
  mLagrange.genPol(x, y);
}

void Dynamics::moveV(Position& pos) {
  pos.move(0, -mSpeedBulletPlayer);
}

/**
 * @brief Dynamics::moveV2
 * @todo change this fonction to make good bullet pattern
 */
void Dynamics::moveV2(Position& pos) {
  pos.move(0, mSpeedEnemy*3);
  // evaluate is reversed ?
  pos.setX(mLagrange.evaluate(pos.y()));
}



void Dynamics::moveH(Position& pos, bool right) {
  if (right)
    pos.move(mSpeedEnemy, 0);
  else
    pos.move(-mSpeedEnemy, 0);
}
