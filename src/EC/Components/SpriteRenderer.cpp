#include "Yekate/Core/Entity.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Yekate/EC/Components/SpriteRenderer.hpp>
#include <Yekate/Core/YKE.hpp>
#include <iostream>

namespace Yekate
{

SpriteRenderer::SpriteRenderer(Entity& en, std::string filepath):
  Component(en),m_trans(en.getComponent<Transform>())
{
  loadTexture(filepath);
}

SpriteRenderer::SpriteRenderer(Entity& en, std::string filepath, sf::Vector2f& scale):
  Component(en),m_trans(en.getComponent<Transform>())
{
  loadTexture(filepath);
  m_sprite.scale(scale);
}
void SpriteRenderer::render(Window& win)
{
  m_sprite.setPosition(m_trans.m_pos);
  win.draw(m_sprite); 
}


void SpriteRenderer::loadTexture(std::string filepath)
{
  if(!m_texture.loadFromFile(filepath))
  {
    printf("couldn't load");
  }
  m_sprite.setTexture(m_texture);
  sf::FloatRect bounds = m_sprite.getLocalBounds();
  m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}
}
