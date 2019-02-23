#include <SFML/Graphics.hpp>
#include "scene/scene.h"
#include "actors/actor.h"
#include "actors/player.cpp"
#include "actors/ball.cpp"
#include "actors/obstacles.cpp"
#include "utils/getche.cpp"
#include <vector>

using namespace std;

vector<int> windowSize = {1000, 500};
const int margin = 10;

// Scene
Scene scene(windowSize, margin);

void render(vector<shared_ptr<Actor>> &world)
{
    sf::RenderWindow window(sf::VideoMode(windowSize[0], windowSize[1]), "The Game");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;

            // control
            // case sf::Event::KeyPressed:
            //     if (event.key.code == sf::Keyboard::Up)
            //         player1.moveUp();
            //     if (event.key.code == sf::Keyboard::Down)
            //         player1.moveDown();
            //     if (event.key.code == sf::Keyboard::Q)
            //         window.close();
            //     break;

            // we don't process other types of events
            default:
                break;
            }
        }
        window.clear();

        window.draw(scene.getFrame());

        for (auto it = world.begin(); it != world.end(); ++it)
            window.draw(*((*it)->getShape()));

        // window.draw(*ball1.getShape());
        // window.draw(*ball2.getShape());
        // window.draw(*ball3.getShape());
        // window.draw(*ball4.getShape());
        // for (auto it = obstacles.begin(); it != obstacles.end(); ++it)
        //     window.draw(*(it->getShape()));

        // window.draw(*player1.getShape());

        window.display();
    }
}

void moveBall(vector<shared_ptr<Actor>> &world)
{
    while (true)
    {
        for (auto it = world.begin(); it != world.end(); ++it)
            if ((*it)->getType() == "ball")
                (*it)->move(2000);
    }
}

void moveObstacles(vector<shared_ptr<Actor>> &world)
{
    while (true)
    {
        for (auto it = world.begin(); it != world.end(); ++it)
            if ((*it)->getType() == "obstacle")
                (*it)->move(10000);
    }
}

void startObstacles(vector<shared_ptr<Actor>> &world)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10); // distribution in range [1, 6]
    for (auto it = world.begin(); it != world.end(); ++it)
        if ((*it)->getType() == "obstacle")
        {
            dynamic_pointer_cast<Obstacle>(*it)->start();
            usleep(500000 * dist(rng));
        }
}

int main()
{
    // world - container of all graphical elements
    vector<shared_ptr<Actor>> world;

    // Player
    shared_ptr<Player> ptr = make_shared<Player>();
    world.push_back(dynamic_pointer_cast<Actor>(ptr));

    // Balls
    shared_ptr<Ball> ball1 = make_shared<Ball>(1, 1);
    shared_ptr<Ball> ball2 = make_shared<Ball>(-1, -1);
    shared_ptr<Ball> ball3 = make_shared<Ball>(-1, 1);
    shared_ptr<Ball> ball4 = make_shared<Ball>(1, -1);
    world.push_back(dynamic_pointer_cast<Actor>(ball1));
    world.push_back(dynamic_pointer_cast<Actor>(ball2));
    world.push_back(dynamic_pointer_cast<Actor>(ball3));
    world.push_back(dynamic_pointer_cast<Actor>(ball4));

    // Obstacles
    for (size_t i = 0; i < 10; i++)
    {
        shared_ptr<Obstacle> obstacle = make_shared<Obstacle>();
        world.push_back(dynamic_pointer_cast<Actor>(obstacle));
    }

    // Threads - start the life of elements
    sf::Thread thread1(&render, world);
    sf::Thread thread2(&moveBall, world);
    sf::Thread thread3(&moveObstacles, world);
    sf::Thread thread4(&startObstacles, world);
    thread1.launch();
    thread2.launch();
    thread3.launch();
    thread4.launch();

    return 0;
}