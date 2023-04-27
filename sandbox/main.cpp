#include "Yekate/Core/Input.hpp"
#include "Yekate/ECP/Components/Camera.hpp"
#include "Yekate/Utility/Time.hpp"
#include <Yekate.hpp>
#include <iostream>

using namespace Yekate;

class Reset: public Component
  {
  public:
    Transform &m_transform;
    Transform temp;
    Reset(Transform& transform):m_transform(transform),temp(transform){}
    void update() override
    {

      if(Input::isKeyHeld(sf::Keyboard::Q))
      {
        m_transform = temp;
      }
    }
  };
class Movement : public Component 
  {
  public:
    Transform &m_transform;
    const float speed = 300.f;

    Movement(Transform& transform):
      m_transform(transform){
      timer = 0;
      jumpDuration = 0.2f;
      isJumping = false;
    } 
    float timer;
    float jumpDuration;
    bool isJumping;
    void update() override{
      timer+=Time::delta;
      if(Input::isKeyHeld(sf::Keyboard::A)){
        m_transform.pos.x-=speed*Time::delta;
      }
    else if(Input::isKeyHeld(sf::Keyboard::D)){
        m_transform.pos.x+=speed*Time::delta;
      }
      if(Input::isKeyTapped(sf::Keyboard::Space) && !isJumping)
      {
        isJumping = true;
        timer = 0;
      }

      timer+=Time::delta;
      if(timer<jumpDuration && isJumping)
      {
        m_transform.pos.y-=3000*Time::delta;
      }
    else if(timer > jumpDuration)
      {
        isJumping = false;
        timer = 0;
      }

    }

  };

class Gravity : public Component
  {
  public:
    const float gf = 500;
    Transform &m_transform;

    Gravity(Transform& transform):m_transform(transform){}

    void update() override{
      if(m_transform.pos.y<600)
        m_transform.pos.y += gf*Time::delta;
    }
  };

int main()
{
  YKE::innit();


  Transform pt;
  pt.pos.x = 60;
  pt.pos.y = 60;


  auto scene = YKE::createScene();

  auto player = YKE::createEntity();

  auto playerMovement = YKE::createComponent<Movement>(pt);
  auto gravity = YKE::createComponent<Gravity>(pt);

  player->addComponent(gravity);
  player->addComponent(playerMovement);

  scene.addEntity(player);

  auto playerSprite = YKE::createComponent<Sprite>("res/Sandbox/airplane.png",pt);

  player->addComponent(playerSprite);
  printf("%d",scene.m_id);

  auto camera = YKE::createEntity();
  auto camComp = YKE::createComponent<Camera>(pt);
  camera->addComponent(camComp);

  scene.addEntity(camera);

  Transform towerPos;
  towerPos.pos.x = 300;
  towerPos.pos.y = 200;

  auto tower = YKE::createEntity();
  auto towerSprite = YKE::createComponent<Sprite>("res/Sandbox/mascot.png", towerPos);
  tower->addComponent(towerSprite);
  scene.addEntity(tower);

  auto flappyGame = YKE::createEntity();
  auto resetSystem = YKE::createComponent<Reset>(pt);
  flappyGame->addComponent(resetSystem);
  scene.addEntity(flappyGame);
    



  YKE::setScene(scene);

  YKE::run();

  return 0;
}

