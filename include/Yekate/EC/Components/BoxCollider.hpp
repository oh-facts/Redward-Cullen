#ifndef BOXCOLLIDER_HPP
#define BOXCOLLIDER_HPP

#include "Yekate/Core/Component.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace Yekate
{

class BoxCollider:public Component
  {
    public:
    sf::Vector2f &m_pos;
    sf::Vector2f &m_size;

    sf::RectangleShape m_box;
    
    bool isColliding;

    BoxCollider(sf::Vector2f& pos, sf::Vector2f& size):m_pos(pos),m_size(size){}

    void start() override;
    void update() override;
    void render() override;
  };

}



#endif // !BOXCOLLIDER_HPP
