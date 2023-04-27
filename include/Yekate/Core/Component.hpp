#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SFML/Graphics.hpp>

namespace Yekate
{
class Component
  {
  public:
    virtual void start(){};
    virtual void update(){};
    virtual void render(){};
    virtual ~Component(){};
  };

}
#endif // !COMPONENT_HPP
