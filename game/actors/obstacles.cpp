#include "actor.h"

using namespace std;

// Obstacle
class Obstacle : public Actor
{
    int width = 10, height = 20;

  public:
    Obstacle()
    {
        shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
        (*shape).setFillColor(sf::Color(50, 200, 50));

        // starting position
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(Scene::margin * 2, Scene::windowSize[0] - Scene::margin * 2); // distribution in range [1, 6]
        (*shape).move(dist6(rng), 2 * Scene::margin);
    }

    auto getShape()
    {
        return shape;
    };
    void move(int microseconds)
    {
        int step = 1;
        (*shape).move(0, step);
        usleep(microseconds);
    }
    sf::Vector2f teritory()
    {
        return sf::Vector2f();
    }
};