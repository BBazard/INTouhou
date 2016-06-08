#include "life.hpp"

Life::Life(int initLife) : mLife(initLife) {}

void Life::decreaseLife() { --mLife; }

void Life::increaseLife() { ++mLife; }

int Life::getLife() { return mLife; }
