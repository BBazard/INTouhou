#pragma once

class Life {
 private:
  int mLife;

 public:
  explicit Life(int initLife);
  void increaseLife();
  void decreaseLife();
  int getLife();
};
