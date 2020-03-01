#ifndef __scene_h_
#define __scene_h_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "common.h"

#define DEFAULT_WINDOW_SIZE_X 1000
#define DEFAULT_WINDOW_SIZE_Y 1000
#define DEFAULT_MARGIN 10

using Int = uint32_t;
using sceneSize_t = std::pair<Int, Int>;

class Scene
{
  sf::ConvexShape makeFrame(const int size[], const int margin);
  sf::ConvexShape m_frame;
  // Map map;

public:
  static sceneSize_t m_sceneSize;
  static uint32_t m_margin;
  Scene()
  {
    m_sceneSize = sceneSize_t{DEFAULT_WINDOW_SIZE_X, DEFAULT_WINDOW_SIZE_Y};
    Scene::m_margin = DEFAULT_MARGIN;
    sf::ConvexShape frame = makeFrame();
    this->m_frame = frame;
  };
  Scene(sceneSize_t sceneSize, const int margin)
  {  
    m_sceneSize = sceneSize;
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
    convex.setPoint(1, sf::Vector2f(m_sceneSize.first - m_margin, m_margin));
    convex.setPoint(2, sf::Vector2f(m_sceneSize.first - m_margin, m_sceneSize.second - m_margin));
    convex.setPoint(3, sf::Vector2f(m_margin, m_sceneSize.second - m_margin));
    convex.setFillColor(sf::Color::Black);
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(sf::Color::White);
    return convex;
  }
  static sceneSize_t getSize()
  {
    return m_sceneSize;
  }
};

#endif // !__scene_h_