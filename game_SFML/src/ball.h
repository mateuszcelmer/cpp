#ifndef __ball_h__
#define __ball_h__

#include "actor.h"

using namespace std;

// Ball
class Ball : public Actor
{
  float horDirection = 1, verDirection = 1;
  short radius = 10;

public:
  Ball();
  Ball(float h, float v);
  void init();
  auto getShape();
  void bounceHor();
  void bounceVer();
  void bounceIfNeeded();
  void move(int microseconds);
  Teritory teritory();
};

#endif