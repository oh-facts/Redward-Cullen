#include "Yekate/Core/Window.hpp"
#include <Yekate/Core/Entity.hpp>
#include <memory>

namespace Yekate
{

Entity::Entity(const char* name):m_name(name)
{

}

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


}
