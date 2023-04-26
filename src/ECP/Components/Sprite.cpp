#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Yekate/ECP/Components/Sprite.hpp>
#include <Yekate/Core/YKE.hpp>

namespace Yekate
{

Sprite::Sprite(std::string filepath, Transform& transform):
  m_transform(transform)
{

  if(!m_texture.loadFromFile(filepath))
  {
    printf("couldn't load");
  }
  m_sprite.setTexture(m_texture);
  sf::FloatRect bounds = m_sprite.getLocalBounds();
  m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Sprite::render()
{
  m_sprite.setPosition(m_transform.pos);
  YKE::getWin()->draw(m_sprite); 
}
}
