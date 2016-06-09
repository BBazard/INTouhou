#include "event.hpp"
#include <queue>
#include <iostream>

Event::Event() {
 std::cout << mMove.size() << " empty: " << mMove.empty() << std::endl;
}

void Event::pushDirection(Direction dir) {
  mMove.push(dir);
  std::cout << "push = " << mMove.front();
}

Direction Event::popDirection() {
 std::cout << mMove.size() << " empty: " << mMove.empty() << std::endl;
  if (!mMove.empty()) {
    Direction result = mMove.front();
    mMove.pop();
    return result;
   } else {
    return NONE;
   }
}
