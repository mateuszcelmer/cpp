// render and key control
#include "engine.h"

void render(vector<shared_ptr<Actor>> *world, vector<int> *windowSize, Scene *scene)
{
    sf::RenderWindow window(sf::VideoMode((*windowSize)[0], (*windowSize)[1]), "The Game");
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
                exit(0);
                break;

            // control
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Up)
                    for (auto it = world->begin(); it != world->end(); ++it)
                        if ((*it)->getType() == "player") // złamanie zasady Liskov (z SOLID)
                            dynamic_pointer_cast<Player>(*it)->moveUp();
                if (event.key.code == sf::Keyboard::Down)
                    for (auto it = world->begin(); it != world->end(); ++it)
                        if ((*it)->getType() == "player") // złamanie zasady Liskov (z SOLID)
                            dynamic_pointer_cast<Player>(*it)->moveDown();
                if (event.key.code == sf::Keyboard::Q)
                {
                    window.close();
                    exit(0);
                }
                break;
            default:
                break;
            }
        }
        window.clear();
        window.draw(scene->getFrame());
        for (auto it = world->begin(); it != world->end(); ++it)
            window.draw(*((*it)->getShape()));
        window.display();
    }
}

// check the collision of the objects
bool isCollision(Teritory t1, Teritory t2)
{
    if ((t1.pointBegin.first <= t2.pointBegin.first && t1.pointBegin.second <= t2.pointBegin.second && t1.pointEnd.first >= t2.pointBegin.first && t1.pointEnd.second >= t2.pointBegin.second) ||
        (t1.pointBegin.first <= t2.pointEnd.first && t1.pointBegin.second <= t2.pointEnd.second && t1.pointEnd.first >= t2.pointEnd.first && t1.pointEnd.second >= t2.pointEnd.second) ||
        (t1.pointBegin.first <= t2.pointEnd.first && t1.pointEnd.second >= t2.pointBegin.second && t1.pointEnd.first >= t2.pointEnd.first && t1.pointBegin.second <= t2.pointBegin.second) ||
        (t1.pointBegin.first <= t2.pointBegin.first && t1.pointBegin.second <= t2.pointEnd.second && t1.pointEnd.first >= t2.pointBegin.first && t1.pointEnd.second >= t2.pointEnd.second))
        return true;
    if ((t2.pointBegin.first <= t1.pointBegin.first && t2.pointBegin.second <= t1.pointBegin.second && t2.pointEnd.first >= t1.pointBegin.first && t2.pointEnd.second >= t1.pointBegin.second) ||
        (t2.pointBegin.first <= t1.pointEnd.first && t2.pointBegin.second <= t1.pointEnd.second && t2.pointEnd.first >= t1.pointEnd.first && t2.pointEnd.second >= t1.pointEnd.second) ||
        (t2.pointBegin.first <= t1.pointEnd.first && t2.pointEnd.second >= t1.pointBegin.second && t2.pointEnd.first >= t1.pointEnd.first && t2.pointBegin.second <= t1.pointBegin.second) ||
        (t2.pointBegin.first <= t1.pointBegin.first && t2.pointBegin.second <= t1.pointEnd.second && t2.pointEnd.first >= t1.pointBegin.first && t2.pointEnd.second >= t1.pointEnd.second))
        return true;
    return false;
}

//move balls
void moveBall(vector<shared_ptr<Actor>> *world)
{
    while (true)
    {
        for (auto it = world->begin(); it != world->end(); ++it)
            if ((*it)->getType() == "ball") // złamanie zasady Liskov (z SOLID)
            {
                (*it)->move(2000);
                for (auto it2 = world->begin(); it2 != world->end(); ++it2)
                    if ((*it2)->getType() != "ball") // złamanie zasady Liskov (z SOLID)
                        if (isCollision((*it)->teritory(), (*it2)->teritory()))
                            dynamic_pointer_cast<Ball>(*it)->bounceHor();
            }
    }
}

// move obstacles
void moveObstacles(vector<shared_ptr<Actor>> *world)
{
    while (true)
    {
        for (auto it = world->begin(); it != world->end(); ++it)
            if ((*it)->getType() == "obstacle") // złamanie zasady Liskov (z SOLID)
                (*it)->move(100);
    }
}

// start a motion of each obstacle with a delay
void startObstacles(vector<shared_ptr<Actor>> *world)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10); // distribution in range [1, 6]
    for (auto it = world->begin(); it != world->end(); ++it)
        if ((*it)->getType() == "obstacle") // złamanie zasady Liskov (z SOLID)
        {
            dynamic_pointer_cast<Obstacle>(*it)->start();
            usleep(50000 * dist(rng));
        }
}