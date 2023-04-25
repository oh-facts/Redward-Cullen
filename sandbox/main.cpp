#include "Entity.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include <BSE.hpp>
#include <Input.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>


struct transform
  {
    sf::Vector2f pos;
  };



class ControlComponent : public Component 
  {
  public:
    transform &m_transform;

    ControlComponent(transform& transform):
      m_transform(transform){}

    void update() override{
    if(isKeyHeld(sf::Keyboard::A)){
        m_transform.pos.x--;
      }
    else if(isKeyHeld(sf::Keyboard::D)){
        m_transform.pos.x++;
      }
    else if(isKeyHeld(sf::Keyboard::W))
      {
        m_transform.pos.y++;
      }
    else if(isKeyHeld(sf::Keyboard::S))
      {
        m_transform.pos.y --;
      }
    }

  };
class SpriteComponent : public Component
  {
  public:
    Sprite &m_sprite;
    transform &m_transform;

    SpriteComponent(Sprite& sprite, transform& transform):
      m_sprite(sprite),m_transform(transform)
    {
    }

    void render() override
    {
      m_sprite.draw(m_transform.pos); 
    }
  };

int main()
{
  BSE::innit(800,600,"Redward Cullen Engine");

  
  struct transform pt;
  pt.pos.x = 5;
  pt.pos.y = 5;


  auto scene = BSE::createScene();
  
  auto playerInput = BSE::createComponent<ControlComponent>(pt);
  auto entity = BSE::createEntity();
  

  entity->addComponent(playerInput);

  scene.addEntity(entity);

  Sprite sp("res/Sandbox/mascot.png");
  auto die = BSE::createComponent<SpriteComponent>(sp,pt);

  entity->addComponent(die);
  printf("%d",scene.m_id);
  BSE::setScene(scene);

  BSE::run();

  return 0;
}

