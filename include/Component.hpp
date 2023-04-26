#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SFML/Graphics.hpp>

class Component
{
  public:
   virtual void update(){};
    virtual void render(){};
};

typedef struct Transform
  {
    sf::Vector2f pos;
  } Transform;
#endif // !COMPONENT_HPP
