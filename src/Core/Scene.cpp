#include "Yekate/EC/Components/BoxCollider.hpp"
#include "Yekate/EC/Components/Camera.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include <Yekate/Core/Scene.hpp>
#include <memory>

namespace Yekate
{

void Scene::reset()
{
  
}
void Scene::addEntity(Entity& entity)
{
  m_entities.push_back(std::make_shared<Entity>(entity));
}
}
