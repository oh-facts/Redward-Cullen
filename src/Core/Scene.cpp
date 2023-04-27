#include <Yekate/Core/Scene.hpp>

namespace Yekate
{

void Scene::reset()
{
  
}
void Scene::addEntity(std::shared_ptr<Entity> entity)
{
  m_entities.push_back(entity);
}
}
