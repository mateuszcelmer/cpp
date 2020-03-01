#include <SFML/Graphics.hpp>
#include "engine.h"
#include "scene.h"
#include "object.h"
#include "player.h"
#include "ball.h"
#include "obstacles.h"
#include "map.h"
#include <vector>
#include <thread>

template <class T>
void loadBallBounceables(T &t)
{
    auto temp = std::make_unique<Objects_t>();
    std::for_each(std::cbegin(t), std::cend(t), [&temp](auto &ptr) {
        temp->push_back(ptr);
    });
    Ball::loadBounceables(std::move(temp));
}

int main()
{
    Scene scene;
    Map<Ball, Obstacle> map(scene.getSize(), 4);

    Objects_t objects;
    Obstacles_t obstacles;
    auto player = std::make_shared<Player>();

    objects.push_back(player);
    // Obstacles
    for (size_t i = 0; i < 100; i++)
    {
        auto obstacle = std::make_shared<Obstacle>();
        obstacles.push_back(obstacle);
        objects.push_back(obstacle);
    }
    // Balls
    std::vector<std::shared_ptr<Ball>> balls;
    for (uint8_t i = 0; i < 1; i++)
    {
        auto ball = std::make_shared<Ball>(PointF{500, 500});
        balls.push_back(ball);
        objects.push_back(ball);
        map.insert(ball);
    }

    loadBallBounceables(obstacles);

    // Threads - start the life of elements
    std::thread thread1([&objects, &scene, &player] { render(objects, scene, player); });
    std::thread thread2([&balls, &map] { moveBalls(balls, map); });
    std::thread thread3([&obstacles] { moveObjects(obstacles); });
    std::thread thread4([&obstacles] { startObstaclesRandomly(obstacles); });

    thread4.join();
    thread3.join();
    thread2.join();
    thread1.join();

    return 0;
}