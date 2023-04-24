#include <Scene.hpp>


void Scene::addEntity(std::shared_ptr<Entity> entity)
{
  m_entities.push_back(entity);
}

