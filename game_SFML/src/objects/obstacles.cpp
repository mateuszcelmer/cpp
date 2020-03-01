#include "obstacles.h"

Obstacle::Obstacle()
{
    m_type = "obstacle";
    m_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(m_width, m_height));
    m_shape->setFillColor(sf::Color(50, 200, 50));
    restartPosition();
}

void Obstacle::restartPosition()
{
    // starting position
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(Scene::m_margin * 2, Scene::m_sceneSize.first - Scene::m_margin * 2); // distribution in range [1, 6]
    m_shape->setPosition(dist6(rng), 2 * Scene::m_margin);
}

void Obstacle::start()
{
    m_started = true;
}

void Obstacle::restartIfNeeded()
{
    if (m_shape->getPosition().y > Scene::m_sceneSize.second - Scene::m_margin - m_height)
        restartPosition();
}

void Obstacle::move()
{
    if (m_started)
    {
        int step = 1;
        m_shape->move(0, step);
        restartIfNeeded();
    }
}

Teritory Obstacle::getTeritory() const
{
    Teritory ter;
    ter.pointBegin = std::pair<int, int>(m_shape->getPosition().x, m_shape->getPosition().y);
    ter.pointEnd = std::pair<int, int>(m_shape->getPosition().x + m_width, m_shape->getPosition().y + m_height);
    return ter;
}

void startObstaclesRandomly(Obstacles_t &obstacles, uint32_t delay)
{
    using namespace std::chrono_literals;
    std::for_each(std::begin(obstacles), std::end(obstacles),
                  [=](const auto &el) {
                      std::this_thread::sleep_for(1ms * delay);
                      el->start();
                  });
}