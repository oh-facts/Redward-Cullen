#include "Yekate/Core/Entity.hpp"
#include "Yekate/EC/Components/BoxCollider.hpp"
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

          if(a1!=nullptr && a2!=nullptr)
          {

            if ((a1)->m_box.getGlobalBounds().intersects((a2)->m_box.getGlobalBounds()))
            {
              a1->isColliding = true;
              a2->isColliding = true;
            }
          else
            {
              a1->isColliding = false;
              a2->isColliding = false;
            }
          }
        }
    }
}

}