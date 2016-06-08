#pragma once
#include <SFML/Graphics.hpp>
#include "component.hpp"
#include "system.hpp"
#include "display.hpp"

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
  // systems
  Display mDisplay;

  //std::vector<Animation> mAnimation
  //std::vector<Dynamics> mDynamics
  //std::vector<Event> mEvent
  //std::vector<Hitbox> mHitbox
  //std::vector<Life> mLife
  //std::vector<Position> mPosition
  //std::vector<Shoot> mShoot
  //std::vector<Sprite> mSprite
  //std::vector<Target> mTarget

  // Component
 // std::vector<Life> mLife;
 // std::vector<Position> mPosition;
 // std::vector<Sprite> mSprite;
 // std::vector<Sprite> mSprite;

  std::vector<std::vector<bool>> mBitset;

 public:
  World();
  void createEntity();
  void createPlayer();
};
