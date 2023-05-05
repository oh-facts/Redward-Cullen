#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include "Yekate/Core/Window.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


namespace Yekate
{
class Entity;
class Component 
  {
  private:
    Component();
  public:
    virtual void start(){};
    virtual void update(){};
    virtual void render(Window&){};

    Entity& m_parent;
    virtual ~Component(){};
    Component(Entity& parent):m_parent(parent){};
  };
}
#endif // !COMPONENT_HPP
