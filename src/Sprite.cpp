#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Sprite.hpp>
#include <BSE.hpp>
Sprite::Sprite(std::string filepath)
{
  if(!m_texture.loadFromFile(filepath))
  {
    printf("couldn't load");
  }
  m_sprite.setTexture(m_texture);
}

void Sprite::draw()
{

      BSE::getWin()->draw(m_sprite); 
}

