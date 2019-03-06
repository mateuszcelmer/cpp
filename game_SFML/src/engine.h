#ifndef __engine_h__
#define __engine_h__

#include <vector>
#include <memory>
#include "actor.h"
#include "player.h"
#include "ball.h"
#include "obstacles.h"
using namespace std;

// render and key control
void render(vector<shared_ptr<Actor>> *world, vector<int> *windowSize, Scene *scene);
// check the collision of the objects
bool isCollision(Teritory t1, Teritory t2);
//move balls
void moveBall(vector<shared_ptr<Actor>> *world);
// move obstacles
void moveObstacles(vector<shared_ptr<Actor>> *world);
// start a motion of each obstacle with a delay
void startObstacles(vector<shared_ptr<Actor>> *world);

#endif