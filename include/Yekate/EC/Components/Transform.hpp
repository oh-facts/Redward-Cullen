#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Yekate/Core/Component.hpp"
#include <SFML/System/Vector2.hpp>
namespace Yekate
{
class Transform : public Component
  {
  public:
    Transform(){canMove = true;}
    sf::Vector2f m_pos;
    void start() override;
    void move(sf::Vector2f dir);
    bool canMove;
  };
}

#endif // !DEBUG
