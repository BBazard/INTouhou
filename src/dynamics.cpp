#include "dynamics.hpp"
#include <vector>
#include "position.hpp"
#include "lagrange.hpp"
#include "component.hpp"

Dynamics::Dynamics() : mSpeedBulletPlayer(10), mSpeedEnemy(1) {
}

void Dynamics::genPol(std::vector<float> x, std::vector<float> y) {
  mLagrange.genPol(x, y);
}

void Dynamics::moveV(Position& pos) {
  pos.move(0, -mSpeedBulletPlayer);
}

/**
 * Move according to the pattern specified
 */
void Dynamics::movePattern(Position& pos) {
  pos.move(0, mSpeedEnemy*3);
  pos.setX(mLagrange.evaluate(pos.y()));
}

void Dynamics::moveH(Position& pos, bool right) {
  if (right)
    pos.move(mSpeedEnemy, 0);
  else
    pos.move(-mSpeedEnemy, 0);
}

void Dynamics::genPattern(Position &from, Position &to, PatternType pt) {
  std::vector<float> x;
  std::vector<float> y;
  switch (pt) {
    case PATTERN1:
      if (from.x() < WINDOW_WIDTH/2) {
        x = {from.x(), WINDOW_WIDTH/2, 1};
        y = {from.y(), WINDOW_HEIGHT/2, 1};
      } else {
        x = {from.x(), WINDOW_WIDTH/2, WINDOW_WIDTH-1};
        y = {from.y(), WINDOW_HEIGHT/2, 1};
      }
      break;
    case PATTERN2:
      x = {from.x(), WINDOW_WIDTH/2};
      y = {from.y(), WINDOW_HEIGHT/2};
      break;
    case PATTERN3:
      x = {from.x(), to.x()};
      y = {from.y(), to.y()};
      break;
    default:
      break;
  }
  genPol(y, x);
}

