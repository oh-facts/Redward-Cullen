#include "Yekate/Core/YKE.hpp"
#include <Yekate/ECP/Components/Camera.hpp>
#include <iostream>
namespace Yekate
{

Camera::Camera(Transform& transform):m_transform(transform) 
{

  m_view.reset(sf::FloatRect(0, 0, YKE::getWin()->getSize().x, YKE::getWin()->getSize().y));
}

void Camera::update()
{
  YKE::getWin()->setView(m_view);
  std::cout<<m_transform.pos.x<<std::endl;
  m_view.setCenter(m_transform.pos.x,m_transform.pos.y);
}

}
