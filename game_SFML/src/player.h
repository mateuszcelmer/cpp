#ifndef __player_h__
#define __player_h__

#include "actor.h"

// Player
class Player : public Actor
{
  int width = 20, height = 150;

public:
  Player();

  auto getShape();
  void move(int step);
  void moveUp();
  void moveDown();
  Teritory teritory();
};

#endif