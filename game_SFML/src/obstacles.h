#ifndef __obstacles_h__
#define __obstacles_h__

#include "actor.h"

using namespace std;

// Obstacle
class Obstacle : public Actor
{
  int width = 10, height = 20;
  bool started = false;

public:
  void restartPosition();
  Obstacle();
  auto getShape();
  void start();
  void restartIfNeeded();
  void move(int microseconds);
  Teritory teritory();
};

#endif