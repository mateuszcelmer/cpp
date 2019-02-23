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

// world - container of all graphical elements
vector<shared_ptr<Actor>> world;

// Scene
Scene scene(windowSize, margin);

// Player
Player player1;

// Balls
Ball ball1(1, 1);
Ball ball2(-1, -1);
Ball ball3(-1, 1);
Ball ball4(1, -1);

// Obstacles
vector<Obstacle> obstacles(10);

void render()
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
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Up)
                    player1.moveUp();
                if (event.key.code == sf::Keyboard::Down)
                    player1.moveDown();
                if (event.key.code == sf::Keyboard::Q)
                    window.close();
                break;

            // we don't process other types of events
            default:
                break;
            }
        }
        window.clear();
        window.draw(scene.getFrame());
        window.draw(*ball1.getShape());
        window.draw(*ball2.getShape());
        window.draw(*ball3.getShape());
        window.draw(*ball4.getShape());
        for (size_t i = 0; i < 10; i++)
        {
            window.draw(*obstacles[i].getShape());
        }
        window.draw(*player1.getShape());

        window.display();
    }
}

void moveBall()
{
    while (true)
    {
        ball1.move(2000);
        ball2.move(2000);
        ball3.move(2000);
        ball4.move(2000);
    }
}

void moveObstacles()
{
    while (true)
    {
        for (auto it = obstacles.begin(); it != obstacles.end(); ++it)
            it->move(2000);
    }
}

int main()
{
    sf::Thread thread1(&render);
    sf::Thread thread2(&moveBall);
    sf::Thread thread3(&moveObstacles);
    thread1.launch();
    thread2.launch();
    thread3.launch();

    return 0;
}