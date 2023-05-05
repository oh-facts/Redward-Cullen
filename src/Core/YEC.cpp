#include <Yekate/Core/YEC.hpp>

namespace Yekate
{
namespace YEC
{

std::shared_ptr<Entity> createEntity(const char* name)
{
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  entity->m_name = name;
  return entity;

}
}
}
