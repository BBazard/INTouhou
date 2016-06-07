#pragma once

/**
 * @brief
 *
 * Abstract class
 * Each system runs continuously and perform global actions on every Entity
 */
class System {
 public:
  virtual void run() = 0;
};
