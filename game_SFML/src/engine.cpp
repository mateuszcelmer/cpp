// render and key control
#include "engine.h"

void render(vector<shared_ptr<Actor>> *objects, vector<int> *windowSize, Scene *scene, shared_ptr<Player> *player)
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
                if (event.key.code == sf::Keyboard::Left)
                    (*player)->moveLeft();
                if (event.key.code == sf::Keyboard::Right)
                    (*player)->moveRight();
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
        for (auto it = objects->begin(); it != objects->end(); ++it)
        {
            window.draw(*((*it)->getShape()));
        }
        // window.draw(*(*(*objects)[2])->getShape());
        // window.draw(*(*(*objects)[4])->getShape());
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
void moveBall(vector<shared_ptr<Ball>> *balls, vector<shared_ptr<Obstacle>> *objects)
{
    while (true)
    {
        for (auto it = balls->begin(); it != balls->end(); ++it)
        {
            (*it)->move(2000);
            for (auto obj = objects->begin(); obj != objects->end(); ++obj)
                if (isCollision((*it)->teritory(), (*obj)->teritory()))
                {
                    (*it)->bounceHor();
                    (*obj)->restartPosition();
                }
        }
    }
}

// move obstacles
void moveObstacles(vector<shared_ptr<Obstacle>> *obstacles)
{
    while (true)
    {
        for (auto it = obstacles->begin(); it != obstacles->end(); ++it)
            (*it)->move(100);
    }
}

// start a motion of each obstacle with a delay
void startObstacles(vector<shared_ptr<Obstacle>> *obstacles)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10); // distribution in range [1, 6]

    for (auto it = obstacles->begin(); it != obstacles->end(); ++it)
    {
        (*it)->start();
        usleep(50000 * dist(rng));
    }
}