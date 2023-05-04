#include "Yekate/Core/Entity.hpp"
#include "Yekate/EC/Components/BoxCollider.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/Core/Physics.hpp>
#include <memory>
#include <vector>


namespace Yekate
{

void Physics::update(std::vector<std::shared_ptr<Entity>> entity_list)
{
  for (auto it1 = entity_list.begin(); it1 != entity_list.end(); ++it1)
    {
      for (auto it2 = std::next(it1); it2 != entity_list.end(); ++it2)
        {
          auto a1 = (*it1)->getComponent<BoxCollider>();
          auto a2 = (*it2)->getComponent<BoxCollider>();
          if ((a1)->m_box.getGlobalBounds().intersects((a2)->m_box.getGlobalBounds()))
          {
            a1->isColliding = true;
            a2->isColliding = true;

            sf::Vector2f direction = a1->trans->m_pos - a2->trans->m_pos;
            float absX = std::abs(direction.x);
            float absY = std::abs(direction.y);
            if (absX > absY) {
              // collided horizontally
              a1->collisionDirection.x = (direction.x > 0) ? -1.f : 1.f;
              a2->collisionDirection.x = (direction.x < 0) ? -1.f : 1.f;
            } else {
              // collided vertically
              a1->collisionDirection.y = (direction.y > 0) ? -1.f : 1.f;
              a2->collisionDirection.y = (direction.y < 0) ? -1.f : 1.f;
            }
          }
          else
          {
            a1->resetCollision();
            a2->resetCollision();
          }


        }
        }
    }
}





