#ifndef __engine_h__
#define __engine_h__

#include <vector>
#include <memory>
#include "object.h"
#include "player.h"
#include "ball.h"
#include "obstacles.h"
#include <thread>
#include <chrono>

// render and key control
void render(objects_t &objects, Scene &scene, std::shared_ptr<Player> player);
// check the collision of the objects
bool isCollision(Teritory t1, Teritory t2);
//move balls
void moveBall(std::vector<std::shared_ptr<Ball>> *balls, std::vector<std::shared_ptr<Obstacle>> *);
// move obstacles
void moveObstacles(std::shared_ptr<std::vector<std::shared_ptr<Object>>> *obstacles);
// start a motion of each obstacle with a delay
void startObstacles(std::shared_ptr<std::vector<std::shared_ptr<Object>>> &obstacles);

template <class T>
void startObjects(T &objects)
{
    std::for_each(std::begin(objects), std::end(objects),
                  [](auto &ptrToObject) {
                      ptrToObject->start();
                  });
}

void moveObjects(std::vector<std::shared_ptr<Moveable>> *moveables);
#endif