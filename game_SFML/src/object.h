#ifndef __Object_h__
#define __Object_h__

#include <SFML/Graphics.hpp>
#include "scene.h"
#include <iostream>
#include <unistd.h>
#include <random>
#include <memory>
#include <string>
#include <thread>

struct Teritory
{
  std::pair<int, int> pointBegin, pointEnd;
};

class Object
{
protected:
  std::string m_type;

public:
  std::shared_ptr<sf::Shape> m_shape;
  virtual Teritory getTeritory() const = 0;
  auto getShape() { return m_shape; }
  auto getType() { return m_type; }

  Object() {}
};

class Moveable
{
  int m_stepDelay_us = 10;

public:
  virtual void move() = 0;
  int getStepDelay() { return m_stepDelay_us; }
  void setStepDelay(int delayInMicroseconds) { m_stepDelay_us = delayInMicroseconds; }
};

using objects_t = std::vector<std::shared_ptr<Object>>;
using moveables_t = std::vector<std::shared_ptr<Moveable>>;

#endif // !__Object_h__
