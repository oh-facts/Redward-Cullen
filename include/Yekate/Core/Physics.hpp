#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include "Yekate/Core/Entity.hpp"
#include <Yekate/EC/Components/BoxCollider.hpp>

namespace Yekate
{
class Physics
  {
  public:
    void update(std::vector<std::shared_ptr<Entity>>);
  };
}

#endif // !PHYSICS_HPP
