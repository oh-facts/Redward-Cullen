#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Yekate/Core/Component.hpp>
#include <memory>
#include <vector>

namespace Yekate
{

class Entity{
  public:
  std::vector<std::shared_ptr<Component>> m_comps;
  
  void start();
  void update();
  void render();
  void addComponent(std::shared_ptr<Component>);
};
}

#endif // !ENTITY_HPP
