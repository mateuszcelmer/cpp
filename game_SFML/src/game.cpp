#include <SFML/Graphics.hpp>
#include "engine.h"
#include "scene.h"
#include "actor.h"
#include "player.h"
#include "ball.h"
#include "obstacles.h"
#include <vector>
#include <thread>

using namespace std;

int main()
{
    vector<int> windowSize = {1000, 1000};
    const int margin = 10;

    // Scene - build the scene
    Scene scene(windowSize, margin);

    // objects - container of all graphical elements
    vector<shared_ptr<Actor>> objects;

    // Player
    shared_ptr<Player> ptr = make_shared<Player>();
    objects.push_back(dynamic_pointer_cast<Actor>(ptr));

    // Balls
    shared_ptr<Ball> ball1 = make_shared<Ball>(1, 1);
    shared_ptr<Ball> ball2 = make_shared<Ball>(-1, -1);
    shared_ptr<Ball> ball3 = make_shared<Ball>(-1, 1);
    shared_ptr<Ball> ball4 = make_shared<Ball>(1, -1);
    objects.push_back(dynamic_pointer_cast<Actor>(ball1));
    objects.push_back(dynamic_pointer_cast<Actor>(ball2));
    objects.push_back(dynamic_pointer_cast<Actor>(ball3));
    objects.push_back(dynamic_pointer_cast<Actor>(ball4));

    // Obstacles
    for (size_t i = 0; i < 100; i++)
    {
        shared_ptr<Obstacle> obstacle = make_shared<Obstacle>();
        objects.push_back(dynamic_pointer_cast<Actor>(obstacle));
    }

    // Threads - start the life of elements
    thread thread1(render, &objects, &windowSize, &scene);
    thread thread2(moveBall, &objects);
    thread thread3(moveObstacles, &objects);
    thread thread4(startObstacles, &objects);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}