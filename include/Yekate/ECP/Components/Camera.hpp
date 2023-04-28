#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Yekate/Core/Component.hpp"
#include <SFML/Graphics/View.hpp>
#include <Yekate/ECP/Properties/Transform.hpp>

namespace Yekate
{

class Camera: public Component
  {
    sf::View m_view;
    Transform& m_transform;
  public:
    Camera(Transform&);
    void update() override;
    void render() override;
  };
}

#endif // !CAMERA_HPP

