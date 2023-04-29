#include "Yekate/Core/Window.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/BoxCollider.hpp>
#include <Yekate/Core/YKE.hpp>
namespace Yekate
{
void BoxCollider::update()
{
  m_box.setPosition(m_pos);
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
}
}

