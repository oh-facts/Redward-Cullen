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
  public:
    virtual void start(){};
    virtual void update(){};
    virtual void render(Window&){};

    std::shared_ptr<Entity> m_parent;
    virtual ~Component(){};
    Component(){m_parent = nullptr;};
  };
}
#endif // !COMPONENT_HPP
