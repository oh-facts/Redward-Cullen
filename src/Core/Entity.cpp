#include "Yekate/Core/Window.hpp"
#include <Yekate/Core/Entity.hpp>
#include <memory>

namespace Yekate
{

void Entity::start()
{
  for(const auto& comp: m_comps)
  {
    comp->start();
  }
}
void Entity::update()
{
  for(const auto& comp: m_comps)
  {
    comp->update();
  }
}

void Entity::render(Window& win)
{
  for(const auto& comp: m_comps)
  {
    comp->render(win);
  }
}


void Entity::addComponent(std::shared_ptr<Component> comp)
{
  comp->m_parent =getptr();
  m_comps.push_back(comp);
}
}
