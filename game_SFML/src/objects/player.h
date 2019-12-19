#ifndef __player_h__
#define __player_h__

#include "object.h"

// Player
class Player : public Object
{
  int m_width = 80, m_height = 20;

public:
  Player();

  void moveLeft();
  void moveRight();
  void move(int);
  Teritory getTeritory() const override;
};

#endif