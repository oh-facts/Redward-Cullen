#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Yekate/Core/Component.hpp"
#include "Yekate/EC/Components/Transform.hpp"
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

namespace Yekate
{

class Camera: public Component
  {
    sf::View m_view;
    std::shared_ptr<Transform> m_pos;
  public:
    Camera(std::shared_ptr<Transform>);
    void update() override;
    void render(Window&) override;
  };
}

#endif // !CAMERA_HPP

