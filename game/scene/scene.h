#ifndef __scene_h_
#define __scene_h_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

class Scene
{
  sf::ConvexShape makeFrame(const int size[], const int margin);
  sf::ConvexShape frame;

public:
  static int windowSize[2];
  static int margin;
  Scene() {}
  Scene(std::vector<int> size, const int margin)
  {
    cout << "ddd" << endl;
    Scene::windowSize[0] = size[0];
    Scene::windowSize[1] = size[1];
    Scene::margin = margin;

    sf::ConvexShape frame = makeFrame();
    this->frame = frame;
  };
  sf::ConvexShape getFrame() { return frame; }
  sf::ConvexShape makeFrame()
  {
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f(margin, margin));
    convex.setPoint(1, sf::Vector2f(windowSize[0] - margin, margin));
    convex.setPoint(2, sf::Vector2f(windowSize[0] - margin, windowSize[1] - margin));
    convex.setPoint(3, sf::Vector2f(margin, windowSize[1] - margin));
    convex.setFillColor(sf::Color::Black);
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(sf::Color::White);
    return convex;
  }
};

int Scene::windowSize[];
int Scene::margin;

#endif // !__scene_h_