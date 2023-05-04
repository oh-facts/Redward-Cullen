#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include "Yekate/Core/Entity.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/BoxCollider.hpp>

namespace Yekate
{
class Physics
  {
  public:
    void update(std::vector<std::shared_ptr<Entity>>);
    sf::Vector2f dir;
  private:
sf::Vector2f calculateCollisionDirection(BoxCollider& a, BoxCollider& b);
  };
}
#endif // !PHYSICS_HPP
