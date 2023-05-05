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
  private:
    Camera();
    sf::View m_view;
    Transform& m_trans;
  public:
    Camera(Entity& en);
    void start() override;
    void update() override;
    void render(Window&) override;
    
  };
}

#endif // !CAMERA_HPP

