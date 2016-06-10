#include "event.hpp"
#include <queue>
#include <iostream>
#include "component.hpp"

Event::Event() {
}

void Event::pushDirection(Direction dir) {
  mMove.push(dir);
}

Direction Event::popDirection() {
  if (!mMove.empty()) {
    Direction result = mMove.front();
    mMove.pop();
    return result;
   } else {
    return NONE;
   }
}
