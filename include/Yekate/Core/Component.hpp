#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include "Yekate/Core/Window.hpp"
#include <SFML/Graphics.hpp>

namespace Yekate
{
class Component
  {
  public:
    virtual void start(){};
    virtual void update(){};
    virtual void render(Window&){};
    virtual ~Component(){};
  };

}
#endif // !COMPONENT_HPP
