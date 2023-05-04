#include "Yekate/EC/Components/BoxCollider.hpp"
#include "Yekate/EC/Components/Camera.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include <Yekate/Core/Scene.hpp>

namespace Yekate
{

void Scene::reset()
{
  
}
void Scene::addEntity(std::shared_ptr<Entity> entity)
{
  m_entities.push_back(entity);
  if(entity->getComponent<BoxCollider>())
  {
    m_entitiesP.push_back(entity);
  }
  if(entity->getComponent<SpriteRenderer>() || entity->getComponent<Camera>())
  {
    m_entitiesR.push_back(entity);
  }
}
}
