#include "ball.h"
#include "obstacles.h"

void Ball::initWithDefaultValues()
{
    m_shape->setFillColor(sf::Color(60, 100, 200));
}

void Ball::randomizePosition()
{
    // randomize starting position
    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_real_distribution<float> dist(-20, 20);
    m_position.first += dist(gen);
    m_position.second += dist(gen);
    m_shape->setPosition(m_position.first, m_position.second);
}

void Ball::randomizeDirectionVector()
{
    // starting direction random
    std::mt19937 rng;
    rng.seed(std::random_device()());
    auto dist = std::uniform_int_distribution<std::mt19937::result_type>(0, M_PI * 2);
    m_direction[0] = sin(dist(rng));
    m_direction[1] = cos(dist(rng));
}

void Ball::bounceFromLeftBound()
{
    m_direction[0] = toPositive(m_direction[0]);
}

void Ball::bounceFromRightBound()
{
    m_direction[0] = toNegative(m_direction[0]);
}

void Ball::bounceFromTopBound()
{
    m_direction[1] = toPositive(m_direction[1]);
}

void Ball::bounceFromBottomBound()
{
    m_direction[1] = toNegative(m_direction[1]);
}

void Ball::bounceFromWallsIfNeeded()
{
    if (m_position.second + m_radius > Scene::m_sceneSize.second - Scene::m_margin)
        bounceFromBottomBound();
    else if (m_position.second - m_radius < Scene::m_margin)
        bounceFromTopBound();
    if (m_position.first + m_radius > Scene::m_sceneSize.first - Scene::m_margin)
        bounceFromRightBound();
    else if (m_position.first - m_radius < Scene::m_margin)
        bounceFromLeftBound();
}

void Ball::move()
{
    int step = 1;
    auto newPosX = m_position.first + step * m_direction[0];
    auto newPosY = m_position.second + step * m_direction[1];

    setPosition(newPosX, newPosY);
    m_shape->setPosition(newPosX - m_radius, newPosY - m_radius);
    // std::cout << "\n{" << m_position.first << ", " << m_position.second << "}" << std::endl;
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
    // usleep(getStepDelay());
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