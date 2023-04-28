#ifndef SPRITERENDERER_HPP
#define SPRITERENDERER_HPP

#include <SFML/System/Vector2.hpp>
#include <Yekate/Core/Component.hpp>

namespace Yekate
{
class SpriteRenderer : public Component
  {
  public:

    sf::Sprite m_sprite; 
    sf::Texture m_texture;
    sf::Vector2f &m_pos;
    int layer;

    SpriteRenderer(std::string, sf::Vector2f& pos);
    
    void render() override;
  };

}

#endif // !SPRITE_HPP
