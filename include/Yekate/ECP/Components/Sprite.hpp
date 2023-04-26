#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <Yekate/Core/Component.hpp>
#include <Yekate/ECP/Properties/Transform.hpp>

namespace Yekate
{
class Sprite : public Component
  {
  public:

    sf::Sprite m_sprite; 
    sf::Texture m_texture;
    Transform &m_transform;

    Sprite(std::string, Transform& transform);
    void render() override;
  };

}

#endif // !SPRITE_HPP
