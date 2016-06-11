#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "component.hpp"
#include "system.hpp"
#include "life.hpp"
#include "sprite.hpp"
#include "position.hpp"
#include "display.hpp"
#include "event.hpp"
#include "playermove.hpp"
#include "keycontroller.hpp"
#include "bulletmove.hpp"
#include "target.hpp"

typedef enum {
  ANIMATION,
  DYNAMICS,
  EVENT,
  HITBOX,
  LIFE,
  POSITION,
  SHOOT,
  SPRITE,
  TARGET,
  COMPONENTNUMBER,
} ComponentType;

/**
 * @brief
 *
 *
 */
class World {
 private:
  sf::RenderWindow mWindow;
  // systems
  Display mDisplay;
  PlayerMove mPlayerMove;
  KeyController mKeyController;
  BulletMove mBulletMove;

  //std::vector<Animation> mAnimation;
  //std::vector<Dynamics> mDynamics;
  std::vector<Event> mEvent;
  //std::vector<Hitbox> mHitbox;
  std::vector<Life> mLife;
  std::vector<Position> mPosition;
  //std::vector<Shoot> mShoot;
  std::vector<Sprite> mSprite;
  std::vector<Target> mTarget;


  std::vector<std::vector<bool>> mBitset;

 public:
  World();
  void createBomb();
  void createBullet();
  void createEnemy();
  void createPlayer();
  void run();

  std::vector<bool>& getBitset(ComponentType type);
  std::vector<Sprite>& getSprites();
  std::vector<Position>& getPositions();
  Event& getEvent(int ind);

 private:
  void createEntity();
};
