#include "actor.h"

// Player
class Player : public Actor
{
    int width = 20, height = 150;

  public:
    Player()
    {
        shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
        (*shape).setFillColor(sf::Color(200, 100, 0));

        // starting position
        (*shape).move(Scene::windowSize[0] - 2 * Scene::margin - width, 2 * Scene::margin);
    };
    auto getShape()
    {
        return shape;
    };
    void move(int step)
    {
        (*shape).move(0, step);
    }
    void moveUp()
    {
        move(-20);
    }
    void moveDown()
    {
        move(20);
    }
    sf::Vector2f teritory()
    {
        return sf::Vector2f();
    }
};