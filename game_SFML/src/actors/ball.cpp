#include "../actor.h"

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
        type = "ball";
        shape = std::make_shared<sf::CircleShape>(radius);
        (*shape).setFillColor(sf::Color(60, 100, 200));
        // starting position
        (*shape).move(Scene::windowSize[0] / 2, Scene::windowSize[1] / 2);
    };
    auto getShape()
    {
        return shape;
    }
    void bounceHor()
    {
        horDirection = -horDirection;
        verDirection = -verDirection;
        shape->move(horDirection, verDirection);
    }
    void bounceVer()
    {
        horDirection = -horDirection;
        shape->move(1 * horDirection, 0);
    }
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
    Teritory teritory()
    {
        Teritory ter;
        ter.pointBegin = pair<int, int>(shape->getPosition().x, shape->getPosition().y);
        ter.pointEnd = pair<int, int>(shape->getPosition().x + 2 * radius, shape->getPosition().y + 2 * radius);
        return ter;
    }
};