#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Sprite.hpp>
#include <BSE.hpp>

Sprite::Sprite(std::string filepath, Transform& transform):
  m_transform(transform)
{

  if(!m_texture.loadFromFile(filepath))
  {
    printf("couldn't load");
  }
  m_sprite.setTexture(m_texture);
}

void Sprite::render()
{
  m_sprite.setPosition(m_transform.pos);
  BSE::getWin()->draw(m_sprite); 
}

