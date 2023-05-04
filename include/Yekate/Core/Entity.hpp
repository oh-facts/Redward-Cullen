#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Yekate/Core/Window.hpp"
#include <Yekate/Core/Component.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Yekate
{

class Entity : public std::enable_shared_from_this<Entity>{
public:
  Entity(){}
  std::shared_ptr<Entity> getptr() {
    return shared_from_this();
  }
  std::vector<std::shared_ptr<Component>> m_comps;
  const char* m_name; 
  void start();
  void update();
  void render(Window&);
  void addComponent(std::shared_ptr<Component>);
  template <typename T>
  T* getComponent();

  //template <typename T>
  //std::shared_ptr<T> getComponent();
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
/*template <typename T>
std::shared_ptr<T> Entity::getComponent() {

  for (auto component : m_comps) {
 std::shared_ptr<T> ptr = std::dynamic_pointer_cast<T>(component);
    if (ptr) {
      return ptr;
    }
  }

  return nullptr;
}*/
}

#endif // !ENTITY_HPP
