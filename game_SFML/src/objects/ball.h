#ifndef ball_h__
#define ball_h__

#include "object.h"

// Ball
class Ball : public Object, public Moveable
{
  short m_radius = 10;
  static std::unique_ptr<const Objects_t> m_bounceablesPtr;

public:
  Ball(PointF position = PointF{0.f, 0.f}) : Object(position)
  {
    m_type = "ball";
    m_shape = std::make_shared<sf::CircleShape>(m_radius);
    initWithDefaultValues();
    randomizeDirectionVector();
    randomizePosition();
    updateShapePosition();
  };
  void updateShapePosition()
  {
    m_shape->setPosition(m_position.first, m_position.second);
  }
  void randomizePosition();
  void randomizeDirectionVector();
  void initWithDefaultValues();
  void bounceFromLeftBound();
  void bounceFromRightBound();
  void bounceFromTopBound();
  void bounceFromBottomBound();
  void bounceFromWallsIfNeeded();
  void move() override;
  Teritory getTeritory() const override;
  static void loadBounceables(std::unique_ptr<const Objects_t> &&);
};

#endif