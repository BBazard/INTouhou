#include "createPlayerBullet.hpp"
#include "world.hpp"

CreatePlayerBullet::CreatePlayerBullet() : mLastTime(0) {
}

void CreatePlayerBullet::run(World &world) {
  int timeBetweenBullet = 200;  //  in milliseconds
  if (world.getTime() > mLastTime + timeBetweenBullet) {
    mLastTime += timeBetweenBullet;
    int X = world.getPosition(0).x() + world.getSprite(0).getSizeX()/2;
    int Y = world.getPosition(0).y() + world.getSprite(0).getSizeY()/2;
    Position m(X, Y);
    world.createBullet(m, "../sprite/bulletPlayer.png", ENEMY);
  }
}

