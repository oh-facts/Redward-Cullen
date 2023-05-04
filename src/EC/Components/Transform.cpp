#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/Transform.hpp>

namespace Yekate
{

void Transform::start()
{
  canMove = false;
  m_pos = sf::Vector2f(0,0);
  printf("hi");
}

void Transform::move(sf::Vector2f dir)
{
  if(canMove)
  {
    m_pos+=dir;
  }
}
}
