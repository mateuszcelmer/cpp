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
  PointF pointBegin, pointEnd;
  PointF getPosition()
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
  PointF m_position;
  PointF m_lastPosition;

public:
  std::shared_ptr<sf::Shape> m_shape;
  virtual Teritory getTeritory() const = 0;
  PointF getPosition() const { return m_position; }
  PointF getPrevPosition() const { return m_lastPosition; }
  void setPosition(PointF position)
  {
    m_lastPosition = m_position;
    m_position = position;
  }
  void setPosition(float x, float y)
  {
    setPosition(PointF{x, y});
  }
  auto getShape() { return m_shape; }
  auto getType() { return m_type; }

  Object(PointF position = PointF{0, 0}) : m_position{position} {}
};

class Moveable
{
  int m_stepDelay_us = 10;

protected:
  std::array<float, 2> m_direction;

public:
  Moveable()
  {
    m_direction = std::array<float, 2>{0, 1};
  }
  virtual void move() = 0;
  int getStepDelay() { return m_stepDelay_us; }
  void setStepDelay(int delayInMicroseconds) { m_stepDelay_us = delayInMicroseconds; }
};

bool isCollision(Teritory &, Teritory &);

using Objects_t = std::vector<std::shared_ptr<Object>>;
using Moveables_t = std::vector<std::shared_ptr<Moveable>>;
using ObjectsPtr = std::shared_ptr<std::vector<std::shared_ptr<Object>>>;

#endif // Object_h__
