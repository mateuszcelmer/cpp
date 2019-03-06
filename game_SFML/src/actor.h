#ifndef __actor_h__
#define __actor_h__

#include <SFML/Graphics.hpp>
#include "scene.h"
#include <iostream>
#include <unistd.h>
#include <random>
#include <memory>
#include <string>
#include <thread>

struct Teritory
{
  pair<int, int> pointBegin, pointEnd;
};

class Actor
{
protected:
  std::shared_ptr<sf::Shape> shape;
  vector<Actor> foreigners;
  string type;

public:
  virtual void move(int ms = 0) = 0;
  virtual Teritory teritory() = 0;
  shared_ptr<sf::Shape> getShape() { return shape; }
  string getType() { return type; }

  Actor() {}
};

#endif // !__actor_h__
