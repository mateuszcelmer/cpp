#include "player.h"

Player::Player()
{
    m_type = "player";
    m_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(m_width, m_height));
    m_shape->setFillColor(sf::Color(200, 100, 0));

    // starting position
    m_shape->move(Scene::m_sceneSize.first / 2 - 2 * Scene::m_margin - m_width / 2, Scene::m_sceneSize.second - Scene::m_margin - m_height);
};

void Player::move(int step)
{
    m_shape->move(step, 0);
}
void Player::moveLeft()
{
    move(-20);
}
void Player::moveRight()
{
    move(20);
}
Teritory Player::getTeritory() const
{
    Teritory ter;
    ter.pointBegin = std::pair<int, int>(m_shape->getPosition().x, m_shape->getPosition().y);
    ter.pointEnd = std::pair<int, int>(m_shape->getPosition().x + m_width, m_shape->getPosition().y + m_height);
    return ter;
}