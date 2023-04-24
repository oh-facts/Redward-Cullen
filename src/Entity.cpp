#include "Component.hpp"
#include <Entity.hpp>

void Entity::update()
{
  for(const auto& comp: m_comps)
  {
    comp->update();
  }
}

void Entity::render()
{
  for(const auto& comp: m_comps)
  {
    comp->render();
  }
}


void Entity::addComponent(std::shared_ptr<Component> comp)
{
  m_comps.push_back(comp);
}

