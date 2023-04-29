#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Yekate/Core/Component.hpp"
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

namespace Yekate
{

class Camera: public Component
  {
    sf::View m_view;
    sf::Vector2f& m_pos; 
  public:
    Camera(sf::Vector2f&);
    void update() override;
    void render(Window&) override;
  };
}

#endif // !CAMERA_HPP

