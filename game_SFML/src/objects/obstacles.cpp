#include "../obstacles.h"

Obstacle::Obstacle()
{
    type = "obstacle";
    shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    shape->setFillColor(sf::Color(50, 200, 50));
    restartPosition();
}

void Obstacle::restartPosition()
{
    // starting position
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(Scene::margin * 2, Scene::windowSize[0] - Scene::margin * 2); // distribution in range [1, 6]
    shape->setPosition(dist6(rng), 2 * Scene::margin);
}

auto Obstacle::getShape()
{
    return shape;
};

void Obstacle::start()
{
    started = true;
}

void Obstacle::restartIfNeeded()
{
    if (shape->getPosition().y > Scene::windowSize[1] - Scene::margin - height)
        restartPosition();
}

void Obstacle::move(int microseconds)
{
    if (started)
    {
        int step = 1;
        shape->move(0, step);
        usleep(microseconds);
        restartIfNeeded();
    }
}

Teritory Obstacle::teritory()
{
    Teritory ter;
    ter.pointBegin = pair<int, int>(shape->getPosition().x, shape->getPosition().y);
    ter.pointEnd = pair<int, int>(shape->getPosition().x + width, shape->getPosition().y + height);
    return ter;
}