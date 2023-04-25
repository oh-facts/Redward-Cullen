#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
class Sprite
  {
    sf::Sprite m_sprite;
    sf::Texture m_texture;
  public:
    Sprite(std::string);
    void draw(sf::Vector2f); 
  };

#endif // !SPRITE_HPP
