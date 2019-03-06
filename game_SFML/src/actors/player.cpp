#include "../player.h"

Player::Player()
{
    type = "player";
    shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    (*shape).setFillColor(sf::Color(200, 100, 0));

    // starting position
    (*shape).move(Scene::windowSize[0] - 2 * Scene::margin - width, 2 * Scene::margin);
};

auto Player::getShape()
{
    return shape;
};
void Player::move(int step)
{
    (*shape).move(0, step);
}
void Player::moveUp()
{
    move(-20);
}
void Player::moveDown()
{
    move(20);
}
Teritory Player::teritory()
{
    Teritory ter;
    ter.pointBegin = pair<int, int>(shape->getPosition().x, shape->getPosition().y);
    ter.pointEnd = pair<int, int>(shape->getPosition().x + width, shape->getPosition().y + height);
    return ter;
}