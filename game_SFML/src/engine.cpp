// render and key control
#include "engine.h"

void render(objects_t &objects, Scene &scene, std::shared_ptr<Player> player)
{
    sf::RenderWindow window(sf::VideoMode(scene.m_windowSize[0], scene.m_windowSize[1]), "The Game");
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
                    player->moveLeft();
                if (event.key.code == sf::Keyboard::Right)
                    player->moveRight();
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
        window.draw(scene.getFrame());
        for (auto it = objects.begin(); it != objects.end(); ++it)
        {
            window.draw(*((*it)->getShape()));
        }
        // window.draw(*(*(*objects)[2])->getShape());
        // window.draw(*(*(*objects)[4])->getShape());
        window.display();
    }
}

void moveObjects(std::vector<std::shared_ptr<Moveable>> *moveables)
{
    while (true)
        std::for_each(std::begin(*moveables),
                      std::end(*moveables),
                      [](auto &el) {
                          el->move();
                      });
}

//move balls
// void moveBall(std::vector<std::shared_ptr<Ball>> *balls, std::vector<std::shared_ptr<Obstacle>> *objects)
// {
//     std::vector<std::thread> th_balls;
//     for (auto b : *balls)
//         th_balls.push_back(std::thread([=]() {
//             while (true)
//             {
//                 b->move(1000);
//                 for (auto obj : *objects)
//                     if (isCollision(b->teritory(), obj->teritory()))
//                     {
//                         b->bounceHor();
//                         obj->restartPosition();
//                     }
//             }
//         }));

//     for (auto &i : th_balls)
//         i.join();
// }

// move obstacles
// void moveObstacles(std::vector<std::shared_ptr<Obstacle>> *obstacles)
// {
//     while (true)
//     {
//         for (auto it = obstacles->begin(); it != obstacles->end(); ++it)
//             (*it)->move(100);
//     }
//     // std::vector<std::thread> th_obst;
//     // for (auto obs : *obstacles)
//     //     th_obst.push_back(std::thread([=]() {
//     //         while (true)
//     //             obs->move(2000);
//     //     }));
//     // for (auto &i : th_obst)
//     //     i.join();
// }

// start a motion of each obstacle with a delay
void startObstacles(std::shared_ptr<std::vector<std::shared_ptr<Object>>> &obstacles)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10); // distribution in range [1, 6]

    for (auto it = (obstacles)->begin(); it != (obstacles)->end(); ++it)
    {
        (dynamic_cast<Obstacle *>(&**it))->start();
        usleep(50000 * dist(rng));
    }
}