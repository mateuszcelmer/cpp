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
using namespace std;

// render and key control
void render(vector<shared_ptr<Object>> *objects, vector<int> *windowSize, Scene *scene, shared_ptr<Player> *player);
// check the collision of the objects
bool isCollision(Teritory t1, Teritory t2);
//move balls
void moveBall(vector<shared_ptr<Ball>> *balls, vector<shared_ptr<Obstacle>> *);
// move obstacles
void moveObstacles(vector<shared_ptr<Obstacle>> *obstacles);
// start a motion of each obstacle with a delay
void startObstacles(vector<shared_ptr<Obstacle>> *obstacles);

#endif