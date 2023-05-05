#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Yekate/Core/Window.hpp"
#include <Yekate/Core/Component.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Yekate
{

class Entity{
public:
  Entity():m_name("default-name"){}
  Entity(const char* name); 
  std::vector<std::shared_ptr<Component>> m_comps;
  const char* m_name; 
  void start();
  void update();
  void render(Window&);
  template <typename T, typename ... T_Args>
  std::shared_ptr<T> addComponent(T_Args && ... args);
  template <typename T>
  T& getComponent();
  template<typename T>
  bool hasComponent() const; 
};
template <typename T>
T& Entity::getComponent() {
  for (auto& component : m_comps) {
    if (typeid(*component) == typeid(T)) {
      return *(std::static_pointer_cast<T>(component));
    }
  }

  throw std::runtime_error("Component not found.");
}
template<typename T>
bool Entity::hasComponent() const {
  for (auto& component : m_comps) {
    if (typeid(*component) == typeid(T)) {
      return true;
    }
  }
  return false;
}
template<typename T, typename... T_Args>
std::shared_ptr<T> Entity::addComponent(T_Args&&... args) {
  std::shared_ptr<T> comp = std::make_shared<T>(*this,std::forward<T_Args>(args)...);

  m_comps.push_back(comp);

  return comp;

}
}
/*
template<typename T, typename...T_Args>
T YEC::createComponent(T_Args && ... args) {
  return T(std::forward<T_Args>(args)...);
}*/

#endif // !ENTITY_HPP
