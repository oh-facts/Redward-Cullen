#ifndef YEC_HPP
#define YEC_HPP

#include "Yekate/Core/Entity.hpp"
namespace Yekate
{

namespace YEC
{

std::shared_ptr<Entity> createEntity(const char* name);
template<typename T, typename...T_Args>
std::shared_ptr<T> createComponent(T_Args && ... args);
  };
template<typename T, typename...T_Args>
std::shared_ptr<T> YEC::createComponent(T_Args && ... args) {
  return std::make_shared<T>(std::forward<T_Args>(args)...);
}
}

#endif // !YEC_HPP
