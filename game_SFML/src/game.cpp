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

    // objects - container of all graphical elements, Actors
    vector<shared_ptr<Actor>> objects;

    // Player
    shared_ptr<Player> player = make_shared<Player>();
    objects.push_back(player);

    // Balls
    vector<shared_ptr<Ball>> balls;
    for (uint8_t i = 0; i < 4; i++)
    {
        shared_ptr<Ball> ball = make_shared<Ball>();
        objects.push_back(ball);
        balls.push_back(ball);
    }

    // Obstacles
    vector<shared_ptr<Obstacle>> obstacles;
    for (size_t i = 0; i < 100; i++)
    {
        shared_ptr<Obstacle> obstacle = make_shared<Obstacle>();
        obstacles.push_back(obstacle);
        objects.push_back(obstacle);
    }

    // Threads - start the life of elements
    thread thread1(render, &objects, &windowSize, &scene, &player);
    thread thread2(moveBall, &balls, &obstacles);
    thread thread3(moveObstacles, &obstacles);
    thread thread4(startObstacles, &obstacles);

    thread4.join();
    thread3.join();
    thread2.join();
    thread1.join();
    return 0;
}