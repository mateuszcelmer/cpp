#include "ball.h"
#include "obstacles.h"

Ball::Ball()
{
    init();
}
Ball::Ball(float h, float v) : m_horDirection{h}, m_verDirection{v}
{
    init();
};
void Ball::init()
{
    m_type = "ball";
    m_shape = std::make_shared<sf::CircleShape>(m_radius);
    m_shape->setFillColor(sf::Color(60, 100, 200));

    // starting position random
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(-20, 20);
    m_shape->move(Scene::m_windowSize[0] / 2 + dist(rng), Scene::m_windowSize[1] / 2 + dist(rng));

    // starting direction random
    dist = std::uniform_int_distribution<std::mt19937::result_type>(0, 200);
    m_horDirection = ((float)dist(rng) - 100) / 100;
    m_verDirection = ((float)dist(rng) - 100) / 100;
}
void Ball::bounceHor()
{
    m_horDirection = -m_horDirection;
    // m_verDirection = -m_verDirection;
    m_shape->move(m_horDirection, m_verDirection);
}
void Ball::bounceVer()
{
    m_horDirection = -m_horDirection;
    m_shape->move(1 * m_horDirection, 0);
}
void Ball::bounceFromWallsIfNeeded()
{
    if (m_shape->getPosition().y > Scene::m_windowSize[1] - Scene::m_margin - m_radius * 2)
        m_verDirection = -m_verDirection;
    else if (m_shape->getPosition().y < Scene::m_margin)
        m_verDirection = -m_verDirection;
    if (m_shape->getPosition().x > Scene::m_windowSize[0] - Scene::m_margin - m_radius * 2)
        m_horDirection = -m_horDirection;
    else if (m_shape->getPosition().x < Scene::m_margin)
        m_horDirection = -m_horDirection;
}

void Ball::move()
{
    int step = 1;
    m_shape->move(step * m_horDirection, step * m_verDirection);
    // TODO dodać warunek if(hasCollision()) bounce();
    bounceFromWallsIfNeeded();
    // TODO nie sprawdzać pozycji wszystkich przeszkód tylko swoją okolicę -> czy tam są jakieś przeszkody
    // for (auto obj : *m_bounceablesPtr)
    //     if (isCollision(getTeritory(), obj->getTeritory()))
    //     {
    //         bounceHor();
    //         ((Obstacle *)&*obj)->restartPosition();
    //     }
    // TODO chyba lepiej użyc std::this_thread::sleep_for()
    usleep(getStepDelay());
}

Teritory Ball::getTeritory() const
{
    Teritory ter;
    ter.pointBegin = std::pair<int, int>(m_shape->getPosition().x, m_shape->getPosition().y);
    ter.pointEnd = std::pair<int, int>(m_shape->getPosition().x + 2 * m_radius, m_shape->getPosition().y + 2 * m_radius);
    return ter;
}

std::unique_ptr<const Objects_t> Ball::m_bounceablesPtr;

void Ball::loadBounceables(std::unique_ptr<const Objects_t> &&bounceablesPtr)
{
    m_bounceablesPtr = std::move(bounceablesPtr);
}