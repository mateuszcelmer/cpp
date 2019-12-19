#ifndef __obstacles_h__
#define __obstacles_h__

#include "object.h"

// Obstacle
class Obstacle : public Object, public Moveable
{
  int m_width = 10, m_height = 10;
  bool m_started = false;

public:
  Obstacle();
  void restartPosition();
  void start();
  void restartIfNeeded();
  void move() override;
  Teritory getTeritory() const override;
};

using obstacles_t = std::vector<std::shared_ptr<Obstacle>>;

#endif