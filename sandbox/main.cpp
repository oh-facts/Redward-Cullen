#include <Yekate.hpp>
#include <iostream>

using namespace Yekate;

class Movement : public Component 
  {
  public:
    sf::Vector2f &m_pos;
    const float speed = 300.f;

    Movement(sf::Vector2f& pos):
      m_pos(pos){
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
        m_pos.x-=speed*Time::delta;
      }
    else if(Input::isKeyHeld(sf::Keyboard::D)){
        m_pos.x+=speed*Time::delta;
      }
      if(Input::isKeyTapped(sf::Keyboard::Space) && !isJumping)
      {
        isJumping = true;
        timer = 0;
      }

      timer+=Time::delta;
      if(timer<jumpDuration && isJumping)
      {
        m_pos.y-=3000*Time::delta;
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
    sf::Vector2f& m_pos;

    Gravity(sf::Vector2f &pos):m_pos(pos){}

    void update() override{
      if(m_pos.y<600)
        m_pos.y += gf*Time::delta;
    }
  };

class Slide : public Component
{
  public:
    float timer = 0;
    sf::Vector2f &m_pos;

    Slide(sf::Vector2f& pos):m_pos(pos){}
    void update() override{
    timer+=Time::delta;
    if(timer<2.5){
        m_pos.x+=300*Time::delta;
      }
    else if(timer>2.5 && timer <5){
        m_pos.x-=300*Time::delta;
      }
    else if(timer>5){
        timer = 0;
      }
    }
  };

int main()
{
  YKE::innit();

  auto player = YKE::createEntity();

  sf::Vector2f py_pos(60,60);
  sf::Vector2f py_box_size(50,50);

  auto playerMovement = YKE::createComponent<Movement>(py_pos);
  auto gravity = YKE::createComponent<Gravity>(py_pos);
  auto playerSprite = YKE::createComponent<SpriteRenderer>("res/Sandbox/airplane.png",py_pos);
  auto playerCollider = YKE::createComponent<BoxCollider>(py_pos,py_box_size);

  playerSprite->layer = 10;

  player->addComponent(playerSprite);
  player->addComponent(playerCollider);
  player->addComponent(gravity);
  player->addComponent(playerMovement);



  auto scene = YKE::createScene();
  scene.addEntity(player);

  // --- //

  sf::Vector2f camPos(960/2,540/2);
  auto camera = YKE::createEntity();
  
  auto camComp = YKE::createComponent<Camera>(camPos);
  camera->addComponent(camComp);

  scene.addEntity(camera);

  // --- //
  
  sf::Vector2f towerPos(100,200);

  auto tower = YKE::createEntity(); 
  
  auto towerSprite = YKE::createComponent<SpriteRenderer>("res/Sandbox/mascot.png", towerPos);
  

  sf::Vector2f towerSize(towerSprite->m_sprite.getGlobalBounds().width,towerSprite->m_sprite.getGlobalBounds().height);
  auto towerCollider = YKE::createComponent<BoxCollider>(towerPos,towerSize);
  

  tower->addComponent(towerSprite);
  tower->addComponent(towerCollider);

  scene.addEntity(tower);
  
  // --- //

  YKE::setScene(scene);
  YKE::run();

  return 0;
}

