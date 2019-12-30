#ifndef ball_h__
#define ball_h__

#include "object.h"

// Ball
class Ball : public Object, public Moveable
{
  float m_horDirection = 1, m_verDirection = 1;
  short m_radius = 10;
  static std::unique_ptr<const Objects_t> m_bounceablesPtr;

public:
  Ball();
  Ball(float h, float v);
  void init();
  void bounceHor();
  void bounceVer();
  void bounceFromWallsIfNeeded();
  void move() override;
  Teritory getTeritory() const override;
  static void loadBounceables(std::unique_ptr<const Objects_t> &&);
};

#endif