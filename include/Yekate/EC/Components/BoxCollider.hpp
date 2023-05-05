#ifndef BOXCOLLIDER_HPP
#define BOXCOLLIDER_HPP

#include "Yekate/Core/Component.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include "Yekate/EC/Components/Transform.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace Yekate
{

class BoxCollider:public Component
  {
  private:
    BoxCollider();
    public:
    Transform& m_trans;
    sf::Vector2f &m_size;
    
    sf::RectangleShape m_box;
    
    bool isColliding;

    BoxCollider(Entity& en, sf::Vector2f& size);

    sf::Vector2f collisionDirection;
    void resetCollision();

    void start() override;
    void update() override;
    void render(Window&) override;
  };

}



#endif // !BOXCOLLIDER_HPP
