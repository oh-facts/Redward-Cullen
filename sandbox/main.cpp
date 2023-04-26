#include <Yekate.hpp>

using namespace Yekate;

class Movement : public Component 
  {
  public:
    Transform &m_transform;
    const float speed = 300.f;

    Movement(Transform& transform):
      m_transform(transform){
  
    }

    void update() override{
       
    if(isKeyHeld(sf::Keyboard::A)){
        m_transform.pos.x-=speed*Time::delta;
      }
    else if(isKeyHeld(sf::Keyboard::D)){
        m_transform.pos.x+=speed*Time::delta;
      }
    else if(isKeyHeld(sf::Keyboard::W))
      {
        m_transform.pos.y-=speed*Time::delta;
      }
    else if(isKeyHeld(sf::Keyboard::S))
      {
        m_transform.pos.y +=speed*Time::delta;
      }
    }

  };

int main()
{
  YKE::innit();

  
  Transform pt;
  pt.pos.x = 0;
  pt.pos.y = 0;


  auto scene = YKE::createScene();
 
  auto player = YKE::createEntity();

  auto playerMovement = YKE::createComponent<Movement>(pt);
  

  player->addComponent(playerMovement);

  scene.addEntity(player);
   
  auto playerSprite = YKE::createComponent<Sprite>("res/Sandbox/mascot.png",pt);

  player->addComponent(playerSprite);
  printf("%d",scene.m_id);
  YKE::setScene(scene);

  YKE::run();

  return 0;
}

