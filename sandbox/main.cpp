#include "Entity.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"
#include <BSE.hpp>
#include <Input.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <filesystem>


class ControlComponent : public Component 
  {
    void update() override
    {
      if(isKeyHeld(sf::Keyboard::A))
      {
        printf("fe");
      }
    }
  };
class DieComponent : public Component
  {
    Sprite sp;
  public:
    DieComponent():sp("res/Sandbox/mascot.png")
    {
    }
    void update() override
    {

      if(isKeyHeld(sf::Keyboard::W))
      {
        printf("dead");
      }
    }
    void render() override
    {
      sp.draw();
    }
  };

int main()
{
  BSE::innit(800,600,"BSE2");
  auto scene = BSE::createScene();

  auto playerInput = BSE::createComponent<ControlComponent>();
  auto entity = BSE::createEntity();

  entity->addComponent(playerInput);

  scene.addEntity(entity);


  auto die = BSE::createComponent<DieComponent>();

  entity->addComponent(die);
  printf("%d",scene.m_id);
  BSE::setScene(scene);

  BSE::run();

  return 0;
}

