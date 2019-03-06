#ifndef __player_h__
#define __player_h__

#include "actor.h"

// Player
class Player : public Actor
{
  int width = 80, height = 20;

public:
  Player();

  auto getShape();
  void move(int step);
  void moveLeft();
  void moveRight();
  Teritory teritory();
};

#endif