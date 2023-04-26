#include <Sprite.hpp>
#include <BSE.hpp>
#include <Input.hpp>





class Movement : public Component 
  {
  public:
    Transform &m_transform;

    Movement(Transform& transform):
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
        m_transform.pos.y--;
      }
    else if(isKeyHeld(sf::Keyboard::S))
      {
        m_transform.pos.y++ ;
      }
    }

  };

int main()
{
  BSE::innit(800,600,"Redward Cullen Engine");

  
  Transform pt;
  pt.pos.x = 5;
  pt.pos.y = 5;


  auto scene = BSE::createScene();
 
  auto player = BSE::createEntity();

  auto playerMovement = BSE::createComponent<Movement>(pt);
  

  player->addComponent(playerMovement);

  scene.addEntity(player);
   
  auto playerSprite = BSE::createComponent<Sprite>("res/Sandbox/mascot.png",pt);

  player->addComponent(playerSprite);
  printf("%d",scene.m_id);
  BSE::setScene(scene);

  BSE::run();

  return 0;
}

