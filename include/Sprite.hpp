#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Component.hpp>
//

class Sprite : public Component
  {
  public:

    sf::Sprite m_sprite; 
    sf::Texture m_texture;
    Transform &m_transform;

    Sprite(std::string, Transform& transform);
    void render() override;
  };


#endif // !SPRITE_HPP
