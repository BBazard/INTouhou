#ifndef PLAYERMOVE_H
#define PLAYERMOVE_H
#include "system.hpp"

class PlayerMove : public System{
 public:
  PlayerMove();
  void run(World &world);
};

#endif // PLAYERMOVE_H
