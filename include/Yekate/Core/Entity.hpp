#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Yekate/Core/Window.hpp"
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
  void render(Window&);
  void addComponent(std::shared_ptr<Component>);
template <typename T>
T* getComponent();

};

template <typename T>
T* Entity::getComponent() {

  for (auto& component : m_comps) {
        if (typeid(*component) == typeid(T)) {
            return static_cast<T*>(component.get());
        }
    }

    return nullptr;
}
}

#endif // !ENTITY_HPP
