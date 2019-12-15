#ifndef __obstacles_h__
#define __obstacles_h__

#include "object.h"

using namespace std;

// Obstacle
class Obstacle : public Object
{
  int width = 10, height = 10;
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