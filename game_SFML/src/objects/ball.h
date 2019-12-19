#ifndef ball_h__
#define ball_h__

#include "object.h"

using ObstaclesPtr = std::shared_ptr<std::vector<std::shared_ptr<Object>>>;

// Ball
class Ball : public Object, public Moveable
{
  float m_horDirection = 1, m_verDirection = 1;
  short m_radius = 10;
  static std::unique_ptr<const objects_t> m_bounceablesPtr;

public:
  Ball();
  Ball(float h, float v);
  void init();
  void bounceHor();
  void bounceVer();
  void bounceIfNeeded();
  void move() override;
  Teritory getTeritory() const override;
  static void loadBounceables(std::unique_ptr<const objects_t> &&);
};

#endif