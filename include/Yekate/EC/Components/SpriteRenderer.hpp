#ifndef SPRITERENDERER_HPP
#define SPRITERENDERER_HPP

#include "Yekate/EC/Components/Transform.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate/Core/Component.hpp>

namespace Yekate
{
class SpriteRenderer : public Component
  {
  private:
    SpriteRenderer();
    void loadTexture(std::string);
  public:

    sf::Sprite m_sprite; 
    sf::Texture m_texture;
    Transform& m_trans;
    int layer;
    
    SpriteRenderer(Entity& en, std::string);
    SpriteRenderer(Entity& en, std::string, sf::Vector2f& scale);
    void render(Window&) override;
  };

}

#endif // !SPRITE_HPP
