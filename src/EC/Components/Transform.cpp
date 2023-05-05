#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/Transform.hpp>
#include <iostream>

namespace Yekate
{

void Transform::start()
{
  canMove = true;
}

void Transform::move(sf::Vector2f dir)
{
  if(canMove)
  {
    m_pos+=dir;
  }
}

}
