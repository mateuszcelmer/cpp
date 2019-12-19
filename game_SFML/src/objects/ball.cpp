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
void Ball::bounceIfNeeded()
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

void Ball::move()
{
    int step = 1;
    m_shape->move(step * m_horDirection, step * m_verDirection);
    bounceIfNeeded();
    for (auto obj : *m_bounceablesPtr)
        if (isCollision(getTeritory(), obj->getTeritory()))
        {
            bounceHor();
            ((Obstacle *)&*obj)->restartPosition();
        }
    usleep(getStepDelay());
}

Teritory Ball::getTeritory() const
{
    Teritory ter;
    ter.pointBegin = std::pair<int, int>(m_shape->getPosition().x, m_shape->getPosition().y);
    ter.pointEnd = std::pair<int, int>(m_shape->getPosition().x + 2 * m_radius, m_shape->getPosition().y + 2 * m_radius);
    return ter;
}

std::unique_ptr<const objects_t> Ball::m_bounceablesPtr;

void Ball::loadBounceables(std::unique_ptr<const objects_t> &&bounceablesPtr)
{
    m_bounceablesPtr = std::move(bounceablesPtr);
}