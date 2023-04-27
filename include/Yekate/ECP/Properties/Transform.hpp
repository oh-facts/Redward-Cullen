#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <SFML/Graphics.hpp>

namespace Yekate
{
class Transform
  {
  public:
    sf::Vector2f pos;
    Transform(){pos.x = 0; pos.y = 0;}
    
    Transform(const Transform& other) {
      pos.x = other.pos.x;
      pos.y = other.pos.y;
    }

    Transform& operator=(const Transform& other) {
      if (this != &other) {

        pos.x = other.pos.x;
        pos.y = other.pos.y;
      }
      return *this;
    }


  }; 

}

#endif // !TRANSFORM_HPP

