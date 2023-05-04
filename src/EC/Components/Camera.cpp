#include "Yekate/Core/YKE.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/Camera.hpp>
#include <iostream>
#include <memory>
namespace Yekate
{

Camera::Camera(std::shared_ptr<Transform> pos):m_pos(pos) 
{
  m_view.setSize(1280,720);
}

void Camera::render(Window& win)
{
  win.setView(m_view);
}

void Camera::update()
{
  m_view.setCenter(m_pos->m_pos.x,m_pos->m_pos.y);
}

}
