#include "actor.h"

using namespace std;

// Ball
class Ball : public Actor
{
    short horDirection = 1, verDirection = 1;
    short radius = 10;

  public:
    Ball() {}
    Ball(short h, short v) : horDirection{h}, verDirection{v}
    {
        shape = std::make_shared<sf::CircleShape>(radius);
        (*shape).setFillColor(sf::Color(60, 100, 200));
        // starting position
        (*shape).move(Scene::windowSize[0] / 2, Scene::windowSize[1] / 2);
    };
    auto getShape()
    {
        return shape;
    };
    void bounceIfNeeded()
    {
        if ((*shape).getPosition().y > Scene::windowSize[1] - Scene::margin - radius * 2)
            verDirection = -1;
        if ((*shape).getPosition().y < Scene::margin)
            verDirection = 1;
        if ((*shape).getPosition().x > Scene::windowSize[0] - Scene::margin - radius * 2)
            horDirection = -1;
        if ((*shape).getPosition().x < Scene::margin)
            horDirection = 1;
    }
    void move(int microseconds)
    {
        int step = 1;
        (*shape).move(step * horDirection, step * verDirection);
        bounceIfNeeded();
        usleep(microseconds);
    }
    sf::Vector2f teritory()
    {
        return sf::Vector2f();
    }
};