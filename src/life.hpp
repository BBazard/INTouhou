#ifndef LIFE_H
#define LIFE_H


class Life {
 private:
  int mLife;

 public:
  Life(int initLife);
  void increaseLife();
  void decreaseLife();
  int getLife();
};

#endif  // LIFE_H
