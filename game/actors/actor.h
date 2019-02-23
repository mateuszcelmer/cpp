#ifndef __actor_h__
#define __actor_h__

#include <SFML/Graphics.hpp>
#include "../scene/scene.h"
#include <iostream>
#include <unistd.h>
#include <random>
#include <memory>

class Actor
{
protected:
  std::shared_ptr<sf::Shape> shape;

public:
  virtual void move(int ms = 0) = 0;
  virtual sf::Vector2f teritory() = 0;
  Actor() {}
};

#endif // !__actor_h__
