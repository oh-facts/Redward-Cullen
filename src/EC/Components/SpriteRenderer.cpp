#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/SpriteRenderer.hpp>
#include <Yekate/Core/YKE.hpp>

namespace Yekate
{

SpriteRenderer::SpriteRenderer(std::string filepath, sf::Vector2f &pos):
  m_pos(pos)
{

  if(!m_texture.loadFromFile(filepath))
  {
    printf("couldn't load");
  }
  m_sprite.setTexture(m_texture);
  sf::FloatRect bounds = m_sprite.getLocalBounds();
  m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void SpriteRenderer::render()
{
  m_sprite.setPosition(m_pos);
  YKE::getWin()->draw(m_sprite); 
}
}
