#include "Yekate/Core/YKE.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/Camera.hpp>
#include <iostream>
#include <memory>
namespace Yekate
{

Camera::Camera(Entity& en) : Component(en), m_trans(en.getComponent<Transform>())
{
  
}
void Camera::start()
{
  m_view.setSize(1280,720);
}

void Camera::render(Window& win)
{
  win.setView(m_view);
}

void Camera::update()
{
  m_view.setCenter(m_trans.m_pos.x,m_trans.m_pos.y);
}
}
