#include "Yekate/Core/Component.hpp"
#include "Yekate/EC/Components/SpriteRenderer.hpp"
#include "Yekate/EC/Components/Transform.hpp"
#include "Yekate/Utility/Time.hpp"
#include <SFML/System/Vector2.hpp>
#include <Yekate.hpp>
#include <iostream>

using namespace Yekate;
/*
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
*/


sf::Vector2f normalize(sf::Vector2f vec)
{
  float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
  if (length != 0)
    return sf::Vector2f(vec.x / length, vec.y / length);
  return vec;
}

class freeMove : public Component
  {
  public:
    const float speed = 300;
    sf::Vector2f move_input;
    std::shared_ptr<Transform> m_trans;

    freeMove(std::shared_ptr<Transform> hi) : m_trans(hi)
    {

    }

    void update() override{

      move_input = sf::Vector2f(0,0);

      if(Input::isKeyHeld(sf::Keyboard::A)){
        move_input.x = -1;
      }
      if(Input::isKeyHeld(sf::Keyboard::D)){
        move_input.x = 1;
      }
      if(Input::isKeyHeld(sf::Keyboard::W)){
        move_input.y = -1;
      }
      if(Input::isKeyHeld(sf::Keyboard::S)){
        move_input.y = 1;
      }
      move_input = normalize(move_input); 

      m_trans->move(speed*Time::delta*move_input);
 
    }

  };
/*
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
*/
int main()
{
  YKE::innit();

  auto player = YEC::createEntity("player");

  sf::Vector2f py_box_size(20,5);

  auto playerTransform = YEC::createComponent<Transform>();

  playerTransform->m_pos = sf::Vector2f(300,300);
  //auto playerMovement = YKE::createComponent<Movement>(playerTransform);
  auto debugMv = YEC::createComponent<freeMove>(playerTransform);

  //auto gravity = YKE::createComponent<Gravity>(py_pos);
  //auto playerSprite = YKE::createComponent<SpriteRenderer>("res/Sandbox/airplane.png",py_pos);
  auto playerCollider = YEC::createComponent<BoxCollider>(playerTransform,py_box_size);

  //playerSprite->layer = 10;

  //player->addComponent(playerSprite);
  player->addComponent(playerCollider);
  //player->addComponent(gravity);
  
  player->addComponent(debugMv);



  auto scene = YKE::createScene();
  scene.addEntity(player);
// printf("works upto here");
  // --- //

  auto camera = YEC::createEntity("my camera");

  auto camComp = YEC::createComponent<Camera>(playerTransform);
  camera->addComponent(camComp);

  scene.addEntity(camera);

  // --- //
// printf("works upto here");


  auto tower = YEC::createEntity("tower"); 
  //  auto towerSprite = YKE::createComponent<SpriteRenderer>("res/Sandbox/mascot.png", towerPos);


  //  sf::Vector2f towerSize(towerSprite->m_sprite.getGlobalBounds().width,towerSprite->m_sprite.getGlobalBounds().height);
  sf::Vector2f towerSize(40,40); 
  auto towerTransform = YEC::createComponent<Transform>();

  towerTransform->m_pos = sf::Vector2f(0,0);
  auto towerCollider = YEC::createComponent<BoxCollider>(towerTransform,towerSize);


  //tower->addComponent(towerSprite);
  tower->addComponent(towerCollider);

  scene.addEntity(tower);

  // --- //

  sf::Vector2f objectPos(400,400);
  auto debugObject = YEC::createEntity("debug obj");
  auto debugSprite = YEC::createComponent<SpriteRenderer>("res/Sandbox/mascot.png", objectPos);
  debugObject->addComponent(debugSprite);

  scene.addEntity(debugObject);



  YKE::setScene(scene);
  YKE::run();

  return 0;
}

