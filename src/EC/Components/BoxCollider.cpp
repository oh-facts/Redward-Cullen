#include "Yekate/Core/Window.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/BoxCollider.hpp>
#include <Yekate/Core/YKE.hpp>
#include <iostream>
namespace Yekate
{

BoxCollider::BoxCollider(Entity& en,sf::Vector2f& size):Component(en), m_trans(en.getComponent<Transform>()), m_size(size)
{

}

void BoxCollider::update()
{
  
  if(isColliding)
  {
//    printf("%s : %.2f  %.2f\n",m_parent.m_name,collisionDirection.x,collisionDirection.y);
    m_trans.canMove = false;
    m_trans.m_pos-=collisionDirection;
  }
else
  {
    m_trans.canMove = true;
  }

  //std::cout<<m_trans.m_pos.x<<std::endl;
  m_box.setPosition(m_trans.m_pos);
}
void BoxCollider::render(Window& win)
{
  win.draw(m_box); 
}

void BoxCollider::start()
{
  m_box.setOutlineColor(sf::Color::Red);
  m_box.setOutlineThickness(2.f); // set outline thickness to 2 pixels
  m_box.setFillColor(sf::Color::Transparent);
  
  m_box.setSize(m_size);
  m_box.setOrigin(m_size/2.f);

  isColliding = false;
  m_box.setPosition(m_trans.m_pos);
}

void BoxCollider::resetCollision()
  {
 collisionDirection = sf::Vector2f(0.f, 0.f);
  isColliding = false;
}
}

