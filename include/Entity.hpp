#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Component.hpp>
#include <memory>
#include <vector>
class Entity{
  public:
  std::vector<std::shared_ptr<Component>> m_comps;
  void update();
  void render();
  void addComponent(std::shared_ptr<Component>);
};

#endif // !ENTITY_HPP
