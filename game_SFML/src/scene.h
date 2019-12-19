#ifndef __scene_h_
#define __scene_h_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define DEFAULT_WINDOW_SIZE_X 1000;
#define DEFAULT_WINDOW_SIZE_Y 1000;
#define DEFAULT_MARGIN 10;

class Scene
{
  sf::ConvexShape makeFrame(const int size[], const int margin);
  sf::ConvexShape m_frame;

public:
  static int m_windowSize[2];
  static int m_margin;
  Scene()
  {
    Scene::m_windowSize[0] = DEFAULT_WINDOW_SIZE_X;
    Scene::m_windowSize[1] = DEFAULT_WINDOW_SIZE_Y;
    Scene::m_margin = DEFAULT_MARGIN;
    sf::ConvexShape frame = makeFrame();
    this->m_frame = frame;
  };
  Scene(std::vector<int> size, const int margin)
  {
    Scene::m_windowSize[0] = size[0];
    Scene::m_windowSize[1] = size[1];
    Scene::m_margin = margin;
    sf::ConvexShape frame = makeFrame();
    this->m_frame = frame;
  }
  sf::ConvexShape getFrame() { return m_frame; }
  sf::ConvexShape makeFrame()
  {
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f(m_margin, m_margin));
    convex.setPoint(1, sf::Vector2f(m_windowSize[0] - m_margin, m_margin));
    convex.setPoint(2, sf::Vector2f(m_windowSize[0] - m_margin, m_windowSize[1] - m_margin));
    convex.setPoint(3, sf::Vector2f(m_margin, m_windowSize[1] - m_margin));
    convex.setFillColor(sf::Color::Black);
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(sf::Color::White);
    return convex;
  }
};

#endif // !__scene_h_