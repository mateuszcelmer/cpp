#ifndef Object_h__
#define Object_h__

#include <SFML/Graphics.hpp>
#include "scene.h"
#include <iostream>
#include <unistd.h>
#include <random>
#include <memory>
#include <thread>
#include "common.h"

struct Teritory
{
  Point pointBegin, pointEnd;
  Point getPosition()
  {
    auto &x1 = pointBegin.first;
    auto &x2 = pointEnd.first;
    auto &y1 = pointBegin.second;
    auto &y2 = pointEnd.second;
    return {(x1 + x2) / 2, (y1 + y2) / 2};
  }
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

bool isCollision(Teritory &, Teritory &);

using Objects_t = std::vector<std::shared_ptr<Object>>;
using Moveables_t = std::vector<std::shared_ptr<Moveable>>;
using ObjectsPtr = std::shared_ptr<std::vector<std::shared_ptr<Object>>>;

#endif // Object_h__
